// General constants
#define SCREEN_WIDTH  (0.5 * 2048)
#define SCREEN_HEIGHT (0.5 * 1535)
#define WINDOW_NAME "circles"

// Menu constants
#define BACKGROUND_FILENAME "assets/background-small.png"
#define BACKGROUND_X 0
#define BACKGROUND_Y 0
#define TITLE_FILENAME "assets/title-small.png"
#define TITLE_WIDTH 588
#define TITLE_X (0.5 * (SCREEN_WIDTH - TITLE_WIDTH))
#define TITLE_Y (0.05 * SCREEN_HEIGHT)
#define PLAY_FILENAME "assets/play-small.png"
#define PLAY_WIDTH 122
#define PLAY_X (0.25 * SCREEN_WIDTH - 0.5 * PLAY_WIDTH)
#define PLAY_Y (0.45 * SCREEN_HEIGHT)
#define QUIT_FILENAME "assets/quit-small.png"
#define QUIT_WIDTH 160
#define QUIT_X (0.75 * SCREEN_WIDTH - 0.5 * QUIT_WIDTH)
#define QUIT_Y (0.45 * SCREEN_HEIGHT)
#define DIFFICULTY_FILENAME "assets/difficulty-small.png"
#define DIFFICULTY_WIDTH 325
#define DIFFICULTY_X (0.5 * SCREEN_WIDTH - 0.5 * DIFFICULTY_WIDTH)
#define DIFFICULTY_Y (0.8 * SCREEN_HEIGHT)
#define DIFFICULTIES_Y_OFFSET 35
#define EASY_FILENAME "assets/easy-small.png"
#define EASY_WIDTH 83
#define EASY_X DIFFICULTY_X
#define EASY_Y (DIFFICULTY_Y - DIFFICULTIES_Y_OFFSET)
#define MEDIUM_FILENAME "assets/medium-small.png"
#define MEDIUM_WIDTH 118
#define MEDIUM_X (EASY_X + EASY_WIDTH + 17)
#define MEDIUM_Y (DIFFICULTY_Y - DIFFICULTIES_Y_OFFSET)
#define HARD_FILENAME "assets/hard-small.png"
#define HARD_X (MEDIUM_X + MEDIUM_WIDTH + 17)
#define HARD_Y (DIFFICULTY_Y - DIFFICULTIES_Y_OFFSET)
#define MENU_MUSIC "assets/circles.mp3"
#define SELECT_SOUND "assets/select.wav"
#define SPACE_MODE_X CENTER_X
#define SPACE_MODE_Y CENTER_Y + 130
#define SPACE_MODE_ON_COLOR 0x00, 0xff, 0x00, 0xff
#define SPACE_MODE_OFF_COLOR 0xff, 0x00, 0x00, 0xff

// Game constants
#define EARTH_FILENAME "assets/earth-small.png"
#define CENTER_RADIUS 50
#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)
#define PLAYER_APEX_OFFSET 30
#define PLAYER_BOTTOM_OFFSET 10
#define PLAYER_RADIUS_OFFSET 10
#define PLAYER_FILENAME "assets/player-small.png"
#define BG_GREY_COLOR 0xf0, 0xf0, 0xf0, 0xff
#define CENTER_COLOR 0xaf, 0xaf, 0xaf, 0xff
#define BG_WHITE_COLOR 0xff, 0xff, 0xff, 0xff
#define BG_SPACE_COLOR 0x00, 0x00, 0x00, 0xff
#define STAR_COLOR 0xff, 0xff, 0xff, 0xff
#define OBSTACLE_COLOR 0xff, 0x00, 0x00, 0xff
#define PLAYER_COLOR 0x00, 0x00, 0xff, 0xff
#define BIG_STAR 10, 15
#define MEDIUM_STAR 5, 7
#define SMALL_STAR 4, 5
#define TOP_LEFT_OBSTACLE 175, 235
#define TOP_OBSTACLE 235, 295
#define TOP_RIGHT_OBSTACLE 295, 355
#define BOTTOM_RIGHT_OBSTACLE 355, 55
#define BOTTOM_OBSTACLE 55, 115
#define BOTTOM_LEFT_OBSTACLE 115, 175
#define MAX_OBSTACLES 30
#define MAX_RADIUS 600
#define MIN_RADIUS 60
#define DEATH_RADIUS 90
#define OBSTACLE_THICKNESS 10
#define EASY_OBS_CREATION_INTERVAL 400
#define MEDIUM_OBS_CREATION_INTERVAL 300
#define HARD_OBS_CREATION_INTERVAL 200
#define EASY_OBS_RADIUS_UPDATE 3
#define MEDIUM_OBS_RADIUS_UPDATE 4
#define HARD_OBS_RADIUS_UPDATE 4
#define PLAYER_SPACE_X CENTER_X + 60
#define PLAYER_SPACE_Y CENTER_Y - 12
#define PLAYER_SPACE_ROT_X -60
#define PLAYER_SPACE_ROT_Y 12
#define PLAYER_DEGREE_INCR 3
#define ALT_BG_COLOR 0x00, 0x00, 0x00, 0xff
#define GAME_OVER_TITLE "GAME OVER"
#define BACK_TO_MENU_TITLE "MENU"
#define QUIT_TITLE "QUIT"
#define SCORE_TITLE "SCORE"
#define GAME_FONT "assets/04B_20__.ttf"
#define TEXT_COLOR 0x00, 0x00, 0x00, 0xff
#define UNSELECTED_COLOR 0x88, 0x88, 0x88, 0xff
#define SPACE_TEXT_COLOR 0xee, 0xee, 0xee, 0xff
#define SPACE_UNSELECTED_COLOR 0x88, 0x88, 0x88, 0xff
#define GAME_MUSIC "assets/courtesy.mp3"
#define GAME_OVER_MUSIC "assets/safe-in-your-skin.mp3"
#define MAX_SCORE 5999009

//Chrono constants
#define DIGITS_FILENAME "assets/digits-small.png"
#define CHRONO_X 850
#define CHRONO_Y 30
#define DIGIT_OFFSET 20
