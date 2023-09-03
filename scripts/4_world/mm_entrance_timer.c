class mm_entrance_timer : Land_Underground_EntranceBase
{
     const float TRIGGER_DELAY = 900000; // 15 minutes delay in milliseconds
     bool m_PunchedCardUsed;
     bool m_DelayedOpeningTriggered = false;

    ref mm_entrance_panel m_ModifiedPanel; // Reference to the modified panel

    void mm_entrance_timer()
    {
        // Find and link the nearest modified panel
        m_ModifiedPanel = mm_entrance_panel.Cast(GetClosestObject("mm_entrance_panel", 5)); // Search within a 5m radius. Adjust as needed.
    }

    void OnPunchedCardInteract(ItemBase card)
    {
        if (card.IsKindOf("PunchedCard"))
        {
            m_PunchedCardUsed = true;
        }
    }

     void OnDoorStateChangedServer(EUndegroundEntranceState newState)
    {
        if (m_PunchedCardUsed && newState == EUndegroundEntranceState.OPENING_A && !m_DelayedOpeningTriggered)
        {
            // Introduce the delay before the door starts opening
            m_DelayedOpeningTriggered = true;
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.StartOpening, TRIGGER_DELAY, false);
        }
        else
        {
            super.OnDoorStateChangedServer(newState);
        }
    }

    void StartOpening()
    {
        // Continue with the opening process
        m_AnimTimerDoorServer = new AnimationTimer();
        m_AnimTimerDoorServer.Run(AdjustTime(GetOpeningTime()), this, "OnUpdateServer", "OnFinishedTimerServer", 0, false, 1);
        m_NavmeshTimer = new Timer();
        m_NavmeshTimer.Run(3, this, "NavmeshUpdate", NULL, true);
        RequestLatentTransition(AdjustTime(GetOpeningTime()));
    }

    // When the player interacts with the entrance, delegate to the modified panel's Interact method
    void OnPlayerInteract(PlayerBase player)
    {
        if (m_ModifiedPanel)
        {
            m_ModifiedPanel.Interact();
        }
    }
}
