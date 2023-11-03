#include "\vbs2\basic_defines.hpp"
#define __CurrentDir__ \vbs2\customer\plugins\behaviors_petr_simek

//Class necessary for VBS to load the new addon correctly
class CfgPatches
{
	class vbs2_vbs_plugins_behaviors_petr_simek
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.10;
		requiredAddons[] = {
			vbs2_editor, 
			vbs2_people
		};
		modules[] =
		{
			vbs_core_content_module
		};
	};
};

// Adds btset to list of btsets which are loaded automatically
class CfgBehaviorTrees
{
	class behaviors_petr_simek //this is an arbitrary className, it needs to be unique though
	{
		path = "\vbs2\customer\plugins\behaviors_petr_simek\data\behaviors_petr_simek\behaviors_petr_simek.btset"; //This is the relative path to the BT-set file to load
		name = "behaviors_petr_simek"; // This is the btset name duplicated in the configuration
	};
};

class vbs_functions_base;
class CfgFunctions
{
	// Macro to build a function in sripts top folder
	#define MAKE_CORE_FUNCTION(functionName)                                 \
	class fn_vbs_pedro_##functionName : vbs_functions_base                     \
	{                                                                       \
		path = __CurrentDir__\data\scripts\fn_vbs_pedro__##functionName##.sqf;  \
	}

};

// formations
class CfgFormations
{
	class West
	{
		#include "cfgFormations.hpp"
	};

	class East : West
	{
		#include "cfgFormations.hpp"
	};

	class Civ : West
	{
		#include "cfgFormations.hpp"
	};

	class Guer : West
	{
		#include "cfgFormations.hpp"
	};
};

// Defines the new order as available from the Control AI - Military
class CfgAvailableBehaviors
{
	class pedro_team_occupy_public
	{
		icon = "\vbs2\customer\plugins\behaviors_petr_simek\data\behaviors_petr_simek.paa";
		allowRotate = true;

		identity = "generic_team";
		displayname = "Pedro";
		description = "Behaviors_petr_simek";				

		//displayCondition = "\core\addons\plugins\generic_behaviors_public\data\scripts\waypointDisplayCondition.sqf";

		newOrderSubject = "NewOrder";
		
		class RootBehaviors
		{
			group[] = {"behaviors_petr_simek", "behavior_pedro"};
			entity[] = {"generic_behaviors_public", "genericRoot"};
		};
		
		class Parameters
		{
			class orderName
			{
				displayName = "orderName";
				value = "occupy";
				type = "string";
			}
			class orderParameters
			{
				displayName = "orderParameters";
				value = "";
				type = "table";
			};
			class reportCompletedToExternal
			{
				displayName = "reportCompletedToExternal";
				value = "true";
				type = "boolean";
			};
			class debugEnabled
			{
				displayName = "debugEnabled";
				value = "false";
				type = "boolean";
			};
		};
	};
};
