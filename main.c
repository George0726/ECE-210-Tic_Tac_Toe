//Qirui Sun
//Aidan Jennings
//Resse who didnt come to lab
//*****************************************************************************
#include "lab_buttons.h"
#include "Invader.black.h"
#include "BuckyBadger.black.h"		// important information about the image size in here.
#include "BuckyBadger2.black.h"		
/******************************************************************************
 * Global Constants and Variables
 *****************************************************************************/
#define MOVE_PIXELS   	1							// Number of Pixels to move each time.
#define LCD_SIZE_X			240						// X Size of LCD screen in pixels
#define LCD_SIZE_Y			320						// Y Size of LCD screen in pixels
#define LCD_MAX_DRAW_X	LCD_SIZE_X-1	// 0 to LCD_MAX_DRAW_X is = LCD_SIZE_X
#define LCD_MAX_DRAW_Y	LCD_SIZE_Y-1	// 0 to LCD_MAX_DRAW_Y is = LCD_SIZE_Y
#define LCD_HALF_SIZE_X	LCD_SIZE_X/2	// X center of screen in pixels
#define LCD_HALF_SIZE_Y	LCD_SIZE_Y/2	// Y center of screen in pixels
#define	LCD_INIT_X			LCD_HALF_SIZE_X - BUCKY_WIDTH_PXL/2		// Start image in the center of the screen X
#define	LCD_INIT_Y			LCD_HALF_SIZE_Y - BUCKY_HEIGHT_PXL/2	// Start image in the center of the screen Y
#define X_WIDTH_PXL 32
#define X_HEIGHT_PXL 32

#define MENU_ITEM_1_X 160
#define MENU_ITEM_1_Y	75
#define MENU_ITEM_2_X 160
#define MENU_ITEM_2_Y	90
//*****************************************************************************
//*****************************************************************************

uint8_t X_bitmap[] = //32 x 32
{
	0x3e, 0x00, 0x00, 0x7c, //                        
	0x7f, 0x00, 0x00, 0xfe, //                        
	0x7f, 0x00, 0x00, 0xfe, //                        
	0x7f, 0x00, 0x00, 0xfe, //                        
	0x7f, 0x00, 0x00, 0xfe, //
	0x7f, 0x00, 0x00, 0xfe, //  	
	0x0f, 0xf0, 0x0f, 0xf0, //    
	0x0f, 0xf0, 0x0f, 0xf0, //           
	0x0f, 0xf0, 0x0f, 0xf0, //           
	0x0f, 0xf0, 0x0f, 0xf0, //     
	0x0f, 0xf8, 0x1f, 0xf0, // 
  0x0f, 0xfc, 0x3f, 0xf0, //	
	0x00, 0xff, 0xff, 0x00, //     
	0x00, 0xff, 0xff, 0x00, //  
	0x00, 0xff, 0xff, 0x00, //  
	0x00, 0xFF, 0xFF, 0x00, //Midpoint
	0x00, 0xFF, 0xFF, 0x00, //
	0x00, 0xFF, 0xFF, 0x00, //
	0x01, 0xFF, 0xFf, 0x80, //
	0x07, 0xFc, 0x3f, 0xe0, //
	0x0f, 0xF8, 0x1f, 0xf0, //
	0x0f, 0xF0, 0x0f, 0xf0, //
	0x0f, 0xf0, 0x0f, 0xf0, //
	0x0f, 0xf0, 0x0f, 0xf0, //
	0x1f, 0xf0, 0x0f, 0xf8, //     
	0x7f, 0x00, 0x00, 0xfe, //      
	0x7f, 0x00, 0x00, 0xfe, //       
	0x7f, 0x00, 0x00, 0xfe, //        
	0x7f, 0x00, 0x00, 0xfe, //         
	0x7f, 0x00, 0x00, 0xfe, //  
	0x3e, 0x00, 0x00, 0x7c, //	
  0x00, 0x00, 0x00, 0x00,		
};

uint8_t *X = X_bitmap;

uint8_t O_bitmap[] = {

	0x3f, 0xff, 0xff, 0xfc, //                        
	0x7f, 0xff, 0xff, 0xfe, //                        
	0x7f, 0xff, 0xff, 0xfe, //                        
	0xff, 0xff, 0xff, 0xff, //                        
	0xff, 0xff, 0xff, 0xff, //                        
	0xff, 0xff, 0xff, 0xff, //                        
	0xff, 0x80, 0x01, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x00, 0x00, 0xff, //
	0xff, 0x00, 0x00, 0xff, //                        
	0xff, 0x80, 0x01, 0xff, //                        
	0xff, 0xff, 0xff, 0xff, //                        
	0xff, 0xff, 0xff, 0xff, //
	0xff, 0xff, 0xff, 0xff, //                        
	0x7f, 0xff, 0xff, 0xfe, //                        
	0x7f, 0xff, 0xff, 0xfe, //                        
	0x3f, 0xff, 0xff, 0xfc, //
};
uint8_t *O = O_bitmap;

const uint8_t null_sprite[] = {
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, 0x00, //
};
const uint8_t *null_s = null_sprite; //a null sprite that contains nothing but a single byte
	
/*
				BIG F*CKING TO DO LIST
					*Figure out how to compile new files in .axf
					*Write a program to take input of a given user and transfer that into the game
						Get player 1 input and enter that into the game board
						Check to make sure nobody has won the game
						Get player 2 input
						Check to make sure nobody has won the game
						-Other player will have to wait
					*Program that checks to make sure nobody has won the game
					*AI so that can play with only themselves
					

					
					*Somebody should set up the wireless connections and make it so that player 1 and player two are automatically assigned a unique id based on their player # 
					*Make a github?


*/

static char game_title[] = "Tic-Tac-Toe\n";
static char one_player_game[] = "1 Player Vs CPU";
static char two_player_game[] = "2 Player (Wireless)";
static char cursor[] = "-->";
char input[1] = "0"; //Input for the D-Pad, Numbers go clockwise 1-4

int game_board[3][3] = {{0,1,2},
												{1,1,0},
											  {0,2,2}};

uint8_t game_state = 0;
												
			/*Game States:
				0 = No player can do anything, game is either over or has yet to start
				1 = Player 1 is currently taking turn
				2 = Player 2 is currently taking turn
		*/
												
int winner = 0;
int *p_winner	= &winner;			 
int game_mode = 0;
		
		/*Game Modes
				0 = Title Screen			
				1 = Single Player
				2 = Multi-Player
		*/

int init(){
	ece210_initialize_board();
}

char get_player_input(){ //THE OUTPUTS ARE CHARS NOT INTS FUCK
		
	
	bool noinput = 1;
	
	while(noinput){

    if( AlertButtons)
    {
      AlertButtons = false;
			if(btn_up_pressed()){
					input[0] = '1';
					noinput = 0;
			}else if(btn_right_pressed()){
					input[0] = '2';
					noinput = 0;
			}else if(btn_down_pressed()){
					input[0] = '3';
					noinput = 0;
			}else if(btn_left_pressed()){
					input[0] = '4';
					noinput = 0;
			}
		}
	}
	return input[0];
}



void draw_game_screen(){
	
	uint8_t y, x;
	uint8_t sprite_x, sprite_y;
	uint8_t *p_image;									//Pointer so that either the X or the O sprite can be swapped out easier
	
	ece210_lcd_draw_rectangle(75, 10, 0, LCD_MAX_DRAW_X, LCD_COLOR_WHITE); // Draw Gridlines
	ece210_lcd_draw_rectangle(155, 10, 0, LCD_MAX_DRAW_X, LCD_COLOR_WHITE);
	
	ece210_lcd_draw_rectangle(0, LCD_MAX_DRAW_Y, 75, 10, LCD_COLOR_WHITE);
	ece210_lcd_draw_rectangle(0, LCD_MAX_DRAW_Y, 150, 10, LCD_COLOR_WHITE);
	
	for(x=0; x < 3; x++){					//Iterte through each index of the game_board array
		for(y=0; y < 3; y++){
			
			*p_image = *null_s;				//Set the pointer to the null sprite so that by default nothing is drawn
			
			if(game_board[y][x] > 0){ //If there is a 0 value then ignore and move on
				
				if(game_board[y][x] == 1){ //X
					
					p_image = X;
					
				}else if(game_board[y][x] == 2){ //O
					
					p_image = O;
					
				}
				
				ece210_lcd_draw_image((x*80)+(74/3),32,(y*80)+(74/3),32, p_image, LCD_COLOR_CYAN, LCD_COLOR_BLACK); //Draw the sprite at whichever index with the assigned sprite
			}
			
		}
	}
}
			
		
	
	
	//Also draw in sprites for each value of the array 
	


void clear_screen(){
	ece210_lcd_draw_rectangle(0, LCD_MAX_DRAW_X, 0, LCD_MAX_DRAW_Y, LCD_COLOR_BLACK);
}


int main(){

	init();
	uint8_t cursor_pos = MENU_ITEM_1_Y;
	
	//Title Screen Code 
	while(!game_mode){ //Loop until a game is choosen
	
		ece210_lcd_print_string(game_title,160,50,LCD_COLOR_WHITE,LCD_COLOR_BLACK);																	//Draw Menu Items
		ece210_lcd_print_string(one_player_game, MENU_ITEM_1_X, MENU_ITEM_1_Y, LCD_COLOR_RED,LCD_COLOR_BLACK);
		ece210_lcd_print_string(two_player_game, MENU_ITEM_2_X, MENU_ITEM_2_Y, LCD_COLOR_BLUE,LCD_COLOR_BLACK); 
		
		ece210_lcd_draw_rectangle(0, LCD_SIZE_X - MENU_ITEM_1_X, MENU_ITEM_1_Y, 40, LCD_COLOR_BLACK);								//Draw Cursor
		ece210_lcd_print_string(cursor, MENU_ITEM_1_X+38, cursor_pos,LCD_COLOR_BLUE,LCD_COLOR_BLACK);
		
		ece210_lcd_draw_image(200,X_WIDTH_PXL, 130, X_HEIGHT_PXL, X , LCD_COLOR_WHITE, LCD_COLOR_BLACK);						//Draw sprites
		ece210_lcd_draw_image(200,X_WIDTH_PXL, 165, X_HEIGHT_PXL, O , LCD_COLOR_WHITE, LCD_COLOR_BLACK);
		
		get_player_input();																																													//Let player choose game mode
		
		if(input[0] == '1'){
			cursor_pos = MENU_ITEM_1_Y;
		}else if(input[0] == '3'){
			cursor_pos = MENU_ITEM_2_Y;
		}else if(input[0] == '2'){ 																																									//Player selects with the right button on the d-pad
			game_mode = ((cursor_pos - 75)%2)+1; //Set game mode to 1 or 2 based on cursor_pos value, I know it's ugly but it works shut up
			
		}
	 
		
	}
	
	//End Title Screen
	
	clear_screen();
	
	while(game_mode == 1){ //Single Player Game
		
		draw_game_screen();
		
	}
	
	while(game_mode == 2){ //Multi-Player Game
		
		//Establish Connection between player devices
		
		
		
	}


return 0;
									
	
}

//ece210_lcd_draw_rectangle(160,15, 200, 15, LCD_COLOR_BLACK);
//get_player_input();
//ece210_lcd_print_string(input,160,200,LCD_COLOR_WHITE,LCD_COLOR_BLACK);
