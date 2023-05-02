#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

static void
Faculty_init_stats(struct Player *this)
{
  struct faculty_stats *stats = &(this->stats.faculty);
  // FIXME: JA: add constants
  stats->numYearsToRetirement = 30;
  stats->numGrants = 0;
  stats->numCoursesTaught = 0;
  // Coffee accumulation from grad school
  stats->numCupsOfCoffee = 10000;
}

static void
Faculty_print(struct Player *this) 
{
  struct faculty_stats *stats = &(this->stats.faculty);
  assert(this && this->type == FACULTY);   // make sure things are sensible
  printf("FACULTY: name:%s years to retirement:%d grants:%d taught:%d coffee:%d\n",
	 this->name,
	 stats->numYearsToRetirement,
	 stats->numGrants,
	 stats->numCoursesTaught,
	 stats->numCupsOfCoffee);
  Info_print(this->info, stdout);
}

static score_t
Faculty_score(struct Player *this)
{
  NYI();
  return 0;
}

static void
Faculty_get_to_campus(struct Player *this,
		      hours_t h, minutes_t m)
{
  NYI();
}

static struct PlayerMethods Faculty_methods =
  {
   .init_stats = Faculty_init_stats,
   .print = Faculty_print,
   .score = Faculty_score,
   .get_to_campus = Faculty_get_to_campus
  };

void Faculty_init(struct Player *this) {
  this->type = FACULTY; 
  this->methods = &Faculty_methods;
}
