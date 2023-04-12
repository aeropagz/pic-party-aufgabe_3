include_directories(
    "${PROJECT_SOURCE_DIR}/lib/Card"
    "${PROJECT_SOURCE_DIR}/lib/Game"
    "${PROJECT_SOURCE_DIR}/lib/Util"
)
add_library(player Player.cpp ComputerPlayer.cpp HumanPlayer.cpp)