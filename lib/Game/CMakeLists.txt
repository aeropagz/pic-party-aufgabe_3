include_directories(
    "${PROJECT_SOURCE_DIR}/lib/Player"
    "${PROJECT_SOURCE_DIR}/lib/Card"
    "${PROJECT_SOURCE_DIR}/lib/Util"
)

add_library(game Game.cpp Deck.cpp)