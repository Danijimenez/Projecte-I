#ifndef __MODULEHALLOFACES_H__
#define __MODULEHALLOFACES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

struct Scores
{
	int score = 0;
	int character[3] = { 62,62,62 };
	char name[3][65] = { { ' ','!','|','#','$','%','&',' ','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','¿','<','>','?','@','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!','?','_','·','¬' },
	{ ' ','!','|','#','$','%','&',' ','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','¿','<','>','?','@','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!','?','_','·','¬' },
	{ ' ','!','|','#','$','%','&',' ','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','¿','<','>','?','@','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!','?','_','·','¬' } };
	
	const char* screen_name[3] = { nullptr, nullptr, nullptr };

	char score_text[10];
};

class ModuleHallOfAces : public Module
{
public:
	ModuleHallOfAces();
	~ModuleHallOfAces();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect HallOfAces;
	Scores scores[10];

//	int scores[10] = { 0,0,0,0,0,0,0,0,0,0 };

	//char scores_text_1[10];
	//char scores_text_2[10];
	//char scores_text_3[10];
	//char scores_text_4[10];
	//char scores_text_5[10];
	//char scores_text_6[10];
	//char scores_text_7[10];
	//char scores_text_8[10];
	//char scores_text_9[10];
	int temp_hiScore = 0;
	bool ordered;
	int numSwaps = 0;
	int score_aux1, score_aux2;
	int char1_aux1, char1_aux2, char2_aux1, char2_aux2, char3_aux1, char3_aux2;
	bool gate_aces = true;
	int score_index;
	int char_num;

};

#endif // __MODULESCENEKEN_H__