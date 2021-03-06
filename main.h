#define SH 10 //Screen Height
#define SW 15 //Screen Width
#define TS 16 //Tile Size

#define NOSCROLL

#define ELIMIT 32
#define MAPELIMIT 8
#define FLIMIT 32
#define TLIMIT 16
#define SPRITELAYERS 2
#define INVLIMIT 8
#define ENTFRAMES 32
#define TILECOUNT 214 //Set this to the actual number of sprites for best performance.
#define FRAMERATE 30
#define HUDHEIGHT 20
#define MSGDEPTH 32
#define MSGTIME 30

#define SHEETX 128 //Tile sheet size
#define SHEETY 480

#define BIT(x) (1<<x)

#define ANIMPARSE entSet[i].frame[entSet[i].direction+entSet[i].animation]
#define PRESENTENT entSet[i]

#define TITLE "Drip"


SDL_Window* w = NULL;
SDL_Surface* s = NULL;
SDL_Surface* loader = NULL;
SDL_Renderer* r = NULL;
SDL_Texture* t = NULL;
SDL_Rect hudStripper = {0,HUDHEIGHT, SW*TS, SH*TS};
SDL_Event keyIn;
const uint8_t* keyboard = NULL;


SDL_Surface* swtileset[TILECOUNT]; 
SDL_Texture* hwtileset[TILECOUNT];
SDL_Surface* font[128];
SDL_Texture* hwfont[128];
SDL_Surface* bgLayer=NULL;
SDL_Texture* bgTex[3][3];
SDL_Surface* scrollLayer = NULL;


typedef struct entity {
	int x;
	int y;
	unsigned char xSub;
	unsigned char ySub;
	void(*behaviour)(int);
	void(*prevState)(int);
	unsigned char direction;
	unsigned char animation;
	unsigned char collisionClass;
	unsigned char layer;
	unsigned char attack;
	unsigned char status[4];
	uint16_t health;
	unsigned char inventory[INVLIMIT];
	unsigned char frame[FLIMIT];
	unsigned char setframe;
	unsigned char deathframe;
	unsigned char drop[4];
	unsigned char hostile;
	void(*hostileDiag)();
	void(*passiveDiag)();
} entity;

typedef struct item {
	unsigned char type;
	unsigned char status;
} item;

typedef struct inventory {
	item items[INVLIMIT];
	unsigned char selection;
	unsigned char weapon;
} inventory;

typedef struct screen {
	unsigned char* tileLayer;
	unsigned char* collisionLayer;
	unsigned char* entities;
} screen;

typedef struct view {
	unsigned char screen[SW][SH];
	unsigned char layers[SW*TS][SH*TS];
	unsigned char flag;
	unsigned int x;
	unsigned int y;
} view;

typedef struct tunnel {
	int m;
	int c;
	unsigned char type;
} tunnel;

union rng {
	int32_t i32;
	uint32_t ui32;
	char c;
	unsigned char uc;
} rng;

void(*options[6])();

view cornerRoom;

view tilewrapper[3][3];
uint16_t flags=0;

unsigned char spawnSlot=1;
unsigned char nspawnSlot=1;

uint16_t sX = 1;
uint16_t sY = 1;
char scroll = 0;

unsigned char pMaxHealth=100;
unsigned char swordOut=0;
unsigned char dialogueOut=0;

unsigned char animationG=0;

unsigned char nScreen[SW][SH];
unsigned char nlayers[SW*TS][SH*TS];

char* msgBuffer[MSGDEPTH];
unsigned char msgSlot=0;
unsigned char msgOut=0;
unsigned int msgTimeout=0;

unsigned char refresh = 1;

char* menuText;
char mode = 0;
char menuFlag=0;
char menuFirstCall=0;

entity entSet[ELIMIT];
tunnel tunnels[TLIMIT];

inventory pInv;

SDL_Surface* sf1 = NULL;

int cameraX=0;
int cameraY=0;

void entityInitialise();
void entityScroll(int x, int y);
void entityReset();
void entitySpawn(entity in, int x, int y);
void nentityReset();
void nentitySpawn(entity in);
void deadEntityKiller();
void corpseDisposal();
void mapLoader(char entities[SW][SH], char collisions[SW][SH]);
SDL_Surface* surfLoader (SDL_Surface* imgIn, unsigned int sizeX, unsigned int sizeY, unsigned char inSize, unsigned char outSize, unsigned char tNum);
void menu();
void pushMsg(char* inStr);
unsigned int get_diff (int val1, int val2);
uint32_t lfsr (uint32_t shift);
void reroll();
int intersect(unsigned int x, unsigned int y);
void generateTunnels();
uint32_t getrandom();
void setCollision(view* in, int iX, int iY, char stat);
void worldgen(view* in, uint16_t xPos, uint16_t yPos);
void scrollMap();
void image(SDL_Texture* imgIn, int x, int y, int w, int h);
void simage(SDL_Surface* imgIn, int x, int y, int w, int h);
void bgBlit(SDL_Surface* imgIn, int x, int y, int w, int h);
void bgDraw ();
void drawRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, uint32_t colour);
void hudRefresh();
void flip();
char collisionCheck(int x, int y);
void moveX(entity* movEnt, char amount);
void moveY(entity* movEnt, char amount);
void fastMoveX(entity* movEnt, char direction, char speed);
void fastMoveY(entity* movEnt, char direction, char speed);
void snapToGrid(entity* movEnt);
void entityLogic();
void loop();
