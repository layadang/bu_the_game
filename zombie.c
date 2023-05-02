#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

static void
Zombie_init_stats(struct Player *this)
{
  struct zombie_stats *stats = &(this->stats.zombie);
  stats->brainsConsumed = 0;
}

static void
Zombie_print(struct Player *this) 
{
  struct zombie_stats *stats = &(this->stats.zombie);
  assert(this && this->type == ZOMBIE);   // make sure things are sensible
  printf("ZOMBIE: name:%s brains:%d\n",
	 this->name,
	 stats->brainsConsumed);
  Info_print(this->info, stdout);
}

static score_t
Zombie_score(struct Player *this)
{
  NYI();
}

static void
Zombie_get_to_campus(struct Player *this,
		    hours_t hour, minutes_t minute)
{
  NYI();
}

static struct PlayerMethods Zombie_methods =
  {
   .init_stats = Zombie_init_stats,
   .print = Zombie_print,
   .score = Zombie_score,
   .get_to_campus = Zombie_get_to_campus
  };

void Zombie_init(struct Player *this) {
  this->type = ZOMBIE; 
  this->methods = &Zombie_methods;
}
