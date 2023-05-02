#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

/******************************************************************************
  EXAMPLE: BU The Game code : More involved demonstration of using bit
           operations, structs, unions, enums and pointers.
 ******************************************************************************/
//   gcc -g -std=c99 game.c -o game

// The Global state of the game is maintained in one global variable
// called theGameState
struct Game {
  BUID_t nextBUID;
  struct {
    // lists that track all the players of a type
    struct Player *Faculty;
    struct Player *Ugrads;
    struct Player *Grads; 
    struct Player *Zombies;
  } players;
} theGameState = {
  .nextBUID = PLAYER_BUID_MIN,
  .players.Faculty = NULL,
  .players.Ugrads = NULL,
  .players.Grads = NULL,
  .players.Zombies = NULL
};

BUID_t
Game_createBUID()
{
  BUID_t id = theGameState.nextBUID;
  theGameState.nextBUID++;
  return id;
}

struct Player **
Game_player2List(struct Player *p)
{
  assert(p);
  switch (Player_getType(p)) {
  case UGRAD: return &theGameState.players.Ugrads;
  case GRAD: return &theGameState.players.Grads;
  case FACULTY: return &theGameState.players.Faculty;
  case ZOMBIE: return &theGameState.players.Zombies;
  default: assert(0);
  }
  return NULL;
}

void Game_PlayerAdd(struct Player *p) 
{
  struct Player **list;

  list = Game_player2List(p);
  
  // make sure nothing is null before we access it
  assert(p != NULL && list != NULL);
  // chain the current players on to this player
  p->next = *list;
  // make this the first player on the list
  (*list)=p;
}

void Game_listPrint(struct Player **list)
{
  assert( list != NULL );
  struct Player *head = *list;
  int i=0;
  
  while (head) {
    printf("%d : ", i);
    Player_print(head);
    head = head->next;
    i++;
  }
}

static PlayerInfoBits_t
randomInfo(void)
{
  PlayerInfoBits_t info = 0;
  Age_t age; TZ_t tz; YBU_t ybu; Intl_t intl;
  Dex_t dex; Cha_t cha; Hea_t hea;
  bool campus, awake, class, party, date, beer;

  age    = random() & PLAYER_AGE_MAX;
  tz     = random() & PLAYER_TZ_MAX;
  ybu    = random() & PLAYER_YBU_MAX;
  intl   = random() & PLAYER_INTL_MAX;
  dex    = random() & PLAYER_DEX_MAX;
  cha    = random() & PLAYER_CHA_MAX;
  hea    = random() & PLAYER_HEA_MAX;
  hea    = (random() & 1) ? hea : (-1 * hea); 
  campus = random() & 1;
  awake  = random() & 1;
  class  = random() & 1;
  party  = random() & 1;
  date   = random() & 1;
  beer   = random() & 1;

  VPRINT("age:%u tz:%u ybu:%u intl:%u dex:%u cha:%u hea:%d C:%u A:%u I:%u P:%u D:%u B:%u\n",
	 age, tz, ybu, intl, dex, cha, hea, campus, awake, class, party, date, beer);
  
  info = Info_set_Age(info, age);
  info = Info_set_TZ(info, tz);
  info = Info_set_YBU(info, ybu);
  info = Info_set_Intl(info, intl);
  info = Info_set_Dex(info, dex);
  info = Info_set_Cha(info, cha);
  info = Info_set_Hea(info, hea);
  info = (campus) ? Info_setOnCampus(info) : Info_clearOnCampus(info);
  info = (awake) ? Info_setAwake(info) : Info_clearAwake(info);
  info = (class) ? Info_setInClass(info) : Info_clearInClass(info);
  info = (party) ? Info_setPartying(info) : Info_clearPartying(info);
  info = (date) ? Info_setOnDate(info) : Info_clearOnDate(info);
  info = (beer) ? Info_setDrinkingBeer(info) : Info_clearDrinkingBeer(info);
  
  return info;
}

int
main(int argc, char **argv)
{
  int i;
  int n = 10;
  enum PlayerType type;
  BUID_t buid;
  char name[PLAYER_MAX_NAME_LEN];
  struct Player *p;
  PlayerInfoBits_t info;
  
  if (argc>1) n=atoi(argv[1]);
  
  for (i=0; i<n; i++) {
    snprintf(name, PLAYER_MAX_NAME_LEN, "Player %d", i);
    type = random() % PLAYER_NUM_TYPES;
    buid = Game_createBUID();
    VPRINT("%d: type:%s(%d) name:%s buid:%u ", i,
	   Player_type_name(type), type, name, buid);
    info = randomInfo();
    info = Info_set_BUID(info, buid);
    p = Player_new(type, name, info);
    Player_print(p);
    Game_PlayerAdd(p);
    
  }

  fprintf(stderr, "Faculty:\n==============\n");
  Game_listPrint(&theGameState.players.Faculty);

  fprintf(stderr, "Grads:\n==============\n");
  Game_listPrint(&theGameState.players.Grads);

  fprintf(stderr, "Grads:\n==============\n");
  Game_listPrint(&theGameState.players.Ugrads);

  fprintf(stderr, "Zombies:\n==============\n");
  Game_listPrint(&theGameState.players.Zombies);
  
  return 0;
}
