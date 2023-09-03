class CfgPatches
{
	class mm_entrance_timer
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Crafting","DZ_Gear_Consumables","DZ_Gear_Cultivation","DZ_Characters"};
	};
};
class CfgMods
{
	class mm_entrance_timer
	{
		dir = "mm_entrance_timer";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "mm_entrance_timer";
		credits = "";
		author = "MikeJ";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
        dependencies[] = {"World"};
        class defs
        {   
			class worldScriptModule
			{
				value = "";
				files[] = {"mm_entrance_timer/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class Land_Underground_Entrance; // Base class reference
	class Land_Underground_Panel; // Base class reference for the panel

	class mm_entrance_timer : Land_Underground_Entrance
    {
        scope = 2; // 2 means the entity is available in the editor, 1 would mean it's hidden
        displayName = "Entrance with Timer";
        descriptionShort = "An underground entrance with a timer mechanism.";
		model="\DZ\structures_bliss\Underground\Entrance\Underground_Entrance.p3d";
		class Doors
		{
			class Doors1
			{
				displayName="door 1";
				component="Doors1";
				soundPos="doors1_action";
				animPeriod=1;
				initPhase=0;
				initOpened=0.30000001;
				soundOpen="doorWoodFrontOpen";
				soundClose="doorWoodFrontClose";
				soundLocked="doorWoodFrontRattle";
				soundOpenABit="doorWoodFrontOpenABit";
			};
			class Doors2
			{
				displayName="door 2";
				component="Doors2";
				soundPos="doors2_action";
				animPeriod=1;
				initPhase=0;
				initOpened=0.30000001;
				soundOpen="doorWoodFrontOpen";
				soundClose="doorWoodFrontClose";
				soundLocked="doorWoodFrontRattle";
				soundOpenABit="doorWoodFrontOpenABit";
			};
		};
		class AnimationSources
		{
			class EntranceDoor
			{
				source="user";
				initPhase=0;
				animPeriod=60;
			};
			class EntranceLight
			{
				source="user";
				initPhase=0;
				animPeriod=140;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
			class DamageZones
			{
				class door1
				{
					class Health
					{
						hitpoints=1500;
						transferToGlobalCoef=0;
					};
					componentNames[]=
					{
						"doors1"
					};
					fatalInjuryCoef=-1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=2.5;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
				};
				class door2
				{
					class Health
					{
						hitpoints=1500;
						transferToGlobalCoef=0;
					};
					componentNames[]=
					{
						"doors2"
					};
					fatalInjuryCoef=-1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=2.5;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
					
							};
class mm_entrance_panel : Land_Underground_Panel
						{
							scope = 2;
							displayName = "Custom Underground Panel";
							model = "\DZ\structures_bliss\Underground\Entrance\Underground_Panel.p3d";
							hiddenSelections[] = {"LED_Red", "LED_Green"};
						};

	class Land_Underground_Panel_Lever : mm_entrance_panel
						{
							scope = 2;
							displayName = "Underground Panel with Lever";
							model = "\DZ\structures_bliss\Underground\Entrance\Underground_Panel_Lever.p3d";
							hiddenSelections[] = {"LED_Red", "LED_Green"};
								class AnimationSources
								{
									class PanelLever
									{
										source = "user";
										initPhase = 0;
										animPeriod = 0.5;
									};						
								};
							};
						};
					};			
				};
			};
		};
	};
};