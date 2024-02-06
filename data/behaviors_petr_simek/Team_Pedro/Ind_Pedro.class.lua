return {
    Ind_Pedro = {

        description = "Pedro IND",
        simpleClass = true,

        parents = {
            "Base"
        },

        Match = function()
            return self.GetHealth ~= nil
        end,

        behaviors = {
            Prone = {tree = 'stance_prone'},
            Crouch = {tree = 'stance_crouch'},
            Stand = {tree = 'stance_stand'},
            Idle = {tree = 'stance_crouch'},
            PointMan = {tree = 'point_man'},
            Follower = {tree = 'follower'},
        },
    },
}