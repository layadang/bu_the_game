#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

static void
Ugrad_init_stats(struct Player *this)
{
  struct ugrad_stats *stats = &(this->stats.ugrad);

  stats->numYearsToGraduation = 4;
  stats->credits = 0;
  stats->friendCount = 0;
  stats->gpa = 0.0;
  stats->cs210 = false;
}

static void
Ugrad_print(struct Player *this) 
{
  struct ugrad_stats *stats = &(this->stats.ugrad);
  assert(this && this->type == UGRAD);   // make sure things are sensible
  printf("UGRAD: name:%s years to graduation:%d credit:%d friendCouht:%d gpa:%f cs210:%u\n",
	 this->name,
	 stats->numYearsToGraduation,
	 stats->credits,
	 stats->friendCount,
	 stats->gpa,
	 stats->cs210);
  Info_print(this->info, stdout);
}

static score_t
Ugrad_score(struct Player *this)
{
  NYI();
  return 0;
}

static void
Ugrad_get_to_campus(struct Player *this,
		    hours_t hour, minutes_t minute)
{
  NYI();
}

static struct PlayerMethods Ugrad_methods =
  {
   .init_stats = Ugrad_init_stats,
   .print = Ugrad_print,
   .score = Ugrad_score,
   .get_to_campus = Ugrad_get_to_campus
  };

void Ugrad_init(struct Player *this) {
  this->type = UGRAD; 
  this->methods = &Ugrad_methods;
}
