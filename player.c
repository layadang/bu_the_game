#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

extern void Faculty_init(struct Player *);
extern void Ugrad_init(struct Player *);
extern void Grad_init(struct Player *);
extern void Zombie_init(struct Player *);

struct Player *
Player_new(enum PlayerType type, char *name, PlayerInfoBits_t info)
{
  struct Player *p;

  p = malloc(sizeof(struct Player));
  assert(p);
  
  Player_setInfo(p, info);
  strncpy(p->name, name, PLAYER_MAX_NAME_LEN);
  // Initial Static Type specific initilizer
  switch (type) {
  case UGRAD: Ugrad_init(p); break;
  case GRAD: Grad_init(p); break;
  case FACULTY: Faculty_init(p); break;
  case ZOMBIE: Zombie_init(p); break;
  }
  
  Player_init_stats(p);

  return p;
}
