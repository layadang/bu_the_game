#ifndef __PLAYER_H__
#define __PLAYER_H__

#define PLAYER_INFO_MANUAL_BIT_OPS

#include "player_info.h"
#include "faculty_stats.h"
#include "grad_stats.h"
#include "ugrad_stats.h"
#include "zombie_stats.h"

#define PLAYER_MAX_NAME_LEN 80
#define PLAYER_NUM_TYPES 4

enum PlayerType { UGRAD, GRAD, FACULTY, ZOMBIE };

struct Player; // forward declaration;

struct PlayerMethods {
  void (*init_stats)(struct Player *);
  void (*print)(struct Player *);
  score_t (*score)(struct Player *);
  void (*get_to_campus)(struct Player *, hours_t hour, minutes_t minute);
};

struct Player {
  struct PlayerMethods *methods;
  char name[PLAYER_MAX_NAME_LEN];
  struct Player *next;
  
  PlayerInfoBits_t info;
  enum PlayerType type;
  
  union {
    struct faculty_stats faculty;
    struct ugrad_stats ugrad;
    struct grad_stats grad;
    struct zombie_stats zombie;
  } stats;

};

static inline enum PlayerType
Player_getType(struct Player *this)
{
  return this->type;
}

static inline void
Player_setType(struct Player *this, enum PlayerType type)
{
  this->type = type;
}

static inline PlayerInfoBits_t
Player_getInfo(struct Player *this)
{
  return this->info;
}

static inline void
Player_setInfo(struct Player *this, PlayerInfoBits_t info)
{
  this->info = info;
}

// polymorphic methods 
#define CALL(t, m, ...) this->methods->m(t __VA_OPT__(,) __VA_ARGS__)

static inline void
Player_init_stats(struct Player *this) {
  return CALL(this, init_stats);
}

static inline void
Player_print(struct Player *this) {
  return CALL(this, print);
}

static inline score_t
Player_score(struct Player *this) {
  return CALL(this, score);
}

static inline void
Player_get_to_campus(struct Player *this, int hour, int minute)
{
  return CALL(this, get_to_campus, hour, minute);
}

static inline char *
Player_type_name(enum PlayerType type) {
  switch (type) {
  case UGRAD: return "UGRAD";
  case GRAD: return "GRAD";
  case FACULTY: return "FACULTY";
  case ZOMBIE: return "ZOMBIE";
  default: assert(0);
  };
  return NULL;
}

struct Player *
Player_new(enum PlayerType type,  char *name, PlayerInfoBits_t info);

#endif 
