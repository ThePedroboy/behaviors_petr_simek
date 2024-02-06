return {
    Team_Pedro = {

        description = "Pedro group",
        simpleClass = true,

        parents = {
            "Base"
        },

        Match = function()
            return self.GetEntity ~= nil
        end,

        behaviors = {
            Move = {tree = 'group_behaviour'},
            Stealth = {tree = 'stealth_group'},
            Idle = {tree = 'wait_forever'},
        },
    },
}