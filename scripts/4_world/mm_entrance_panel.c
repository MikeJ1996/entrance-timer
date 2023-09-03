class mm_entrance_panel : Land_Underground_Panel
{
     const float PANEL_DELAY = 900000; // 15 minutes delay in milliseconds
     float m_InteractStartTime;
     bool m_PanelActivated;

    void mm_entrance_panel()
    {
        // Initialization if needed
    }

    override bool CanInteract()
    {
        Land_Underground_EntranceBase door = GetLinkedDoor();
        if (door)
        {
            return Land_Underground_EntranceBase.Cast(door).CanManipulate();
        }
        return false;
    }

    override void Interact()
    {
        if (!m_PanelActivated)
        {
            m_PanelActivated = true;
            m_InteractStartTime = GetGame().GetTime();
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                player.MessageStatus("The entrance will be opened in 15 minutes.");
            }
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ExecutePanelInteraction, PANEL_DELAY, false);
        }
        else
        {
            super.Interact();
        }
    }

    private void ExecutePanelInteraction()
    {
        Land_Underground_EntranceBase door = GetLinkedDoor();
        if (door)
        {
            GetGame().RegisterNetworkStaticObject(this);
            Land_Underground_EntranceBase.Cast(door).Manipulate();
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetPanelUsed, 500);
            m_PanelActivated = false;
            SetSynchDirty();
        }
        else
        {
            ErrorEx("Can't find the instance of entrance the panel is linked to");
        }
    }
}
