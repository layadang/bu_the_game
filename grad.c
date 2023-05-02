#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

static void
Grad_init_stats(struct Player *this)
{
  struct grad_stats *stats = &(this->stats.grad);

  stats->numYearsInPhd = 0;
  stats->numPublications = 0;
  stats->numCupsOfCoffee = 0;
}

static void
Grad_print(struct Player *this) 
{
  struct grad_stats *stats = &(this->stats.grad);
  assert(this && this->type == GRAD);   // make sure things are sensible
  printf("GRAD: name:%s years in PhD:%d publications:%d coffee:%d\n",
	 this->name,
	 stats->numYearsInPhd,
	 stats->numPublications,
	 stats->numCupsOfCoffee);
  Info_print(this->info, stdout);
}

static score_t
Grad_score(struct Player *this)
{
  NYI();
  return 0;
}

static void
Grad_get_to_campus(struct Player *this,
		    hours_t hour, minutes_t minute)
{
  NYI();
}

static struct PlayerMethods Grad_methods =
  {
   .init_stats = Grad_init_stats,
   .print = Grad_print,
   .score = Grad_score,
   .get_to_campus = Grad_get_to_campus
  };

void Grad_init(struct Player *this) {
  this->type = GRAD; 
  this->methods = &Grad_methods;
}
