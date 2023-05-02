#include "player.h"

static void
Faculty_init_stats(struct Player *this)
{
  // FIXME: JA: add constants
  this->stats.faculty.numYearsToRetirement = 30;
  this->stats.faculty.numGrants = 0;
  this->stats.faculty.numCoursesTaught = 0;
  // Coffee accumulation from grad school
  this->stats.faculty.numCupsOfCoffee = 10000;
}

static
Player_Faculty_print(struct Player *this) 
{
  struct faculty_stats *stats = &(this->stats.faculty);
  assert(this && this->type == FACULTY);   // make sure things are sensible
  printf("FACULTY: years to retirement: %d grants: %d taught: %d coffee: %d\n",
	 stats->numYearsToRetirement,
	 stats->numGrants,
	 stats->numCoursesTaught,
	 stats->numCupsOfCoffee);
}

static int
Faculty_score(struct Player *this)
{
  NYI();
}

struct PlayerMethods Faculty_vtable =
  {
   .init_stats = Faculty_init_stats,
   .print = Faculty_print,
   .score = Faculty_score
  };

void Faculy_init(struct Player *this) {
  this->type = FACULTY; 
  this.vtable = &Faculty_vtable;
}
