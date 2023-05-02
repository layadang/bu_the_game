#ifndef __PLAYER_INFO_BITS_H__
#define  __PLAYER_INFO_BITS_H__

typedef unsigned long long PlayerInfoBits_t;

enum { PLAYER_AGE_OFFSET    = 0,  PLAYER_AGE_LEN  = 7,
       PLAYER_TZ_OFFSET     = 7,  PLAYER_TZ_LEN   = 5,
       PLAYER_YBU_OFFSET    = 12, PLAYER_YBU_LEN  = 6,
       PLAYER_INTL_OFFSET   = 18, PLAYER_INTL_LEN = 3,
       PLAYER_DEX_OFFSET    = 21, PLAYER_DEX_LEN  = 3,
       PLAYER_CHA_OFFSET    = 24, PLAYER_CHA_LEN  = 3,
       PLAYER_HEA_OFFSET    = 27, PLAYER_HEA_LEN  = 4,
       PLAYER_BUID_OFFSET   = 31, PLAYER_BUID_LEN = 27,
       PLAYER_CAMPUS_OFFSET = 58, 
       PLAYER_AWAKE_OFFSET  = 59,
       PLAYER_CLASS_OFFSET  = 60,
       PLAYER_PARTY_OFFSET  = 61,
       PLAYER_DATE_OFFSET   = 62,
       PLAYER_BEER_OFFSET   = 63 };

#define PLAYER_AGE_MIN  0
#define PLAYER_AGE_MAX  ((1ULL << PLAYER_AGE_LEN) - 1)

#define PLAYER_TZ_MIN  0
#define PLAYER_TZ_MAX  ((1ULL << PLAYER_TZ_LEN) - 1)

#define PLAYER_YBU_MIN  0
#define PLAYER_YBU_MAX  ((1ULL << PLAYER_YBU_LEN) - 1)

#define PLAYER_INTL_MIN  0
#define PLAYER_INTL_MAX  ((1ULL << PLAYER_INTL_LEN) - 1)

#define PLAYER_DEX_MIN  0
#define PLAYER_DEX_MAX  ((1ULL << PLAYER_DEX_LEN) - 1)

#define PLAYER_CHA_MIN  0
#define PLAYER_CHA_MAX  ((1ULL << PLAYER_CHA_LEN) - 1)

#define PLAYER_HEA_MIN  -7
#define PLAYER_HEA_MAX  +7

#define PLAYER_BUID_NULL 0
#define PLAYER_BUID_MIN  1
#define PLAYER_BUID_MAX  ((1ULL << PLAYER_BUID_LEN) - 1)

#define PLAYER_AGE_MASK  (((1ULL << PLAYER_AGE_LEN) - 1) << PLAYER_AGE_OFFSET)
#define PLAYER_TZ_MASK   (((1ULL << PLAYER_TZ_LEN) - 1) << PLAYER_TZ_OFFSET)
#define PLAYER_YBU_MASK  (((1ULL << PLAYER_YBU_LEN) - 1) << PLAYER_YBU_OFFSET)
#define PLAYER_INTL_MASK (((1ULL << PLAYER_INTL_LEN) - 1) << PLAYER_INTL_OFFSET)
#define PLAYER_DEX_MASK  (((1ULL << PLAYER_DEX_LEN) - 1) << PLAYER_DEX_OFFSET)
#define PLAYER_CHA_MASK  (((1ULL << PLAYER_CHA_LEN) - 1) << PLAYER_CHA_OFFSET)
#define PLAYER_HEA_MASK  (((1ULL << PLAYER_HEA_LEN) - 1) << PLAYER_HEA_OFFSET)
#define PLAYER_BUID_MASK (((1ULL << PLAYER_BUID_LEN) - 1) << PLAYER_BUID_OFFSET)


void Info_print(PlayerInfoBits_t info, FILE *file);

static inline Age_t
Info_get_Age(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_AGE_MASK;
  value = value >> PLAYER_AGE_OFFSET;
  return (Age_t)value;
}

static inline PlayerInfoBits_t
Info_set_Age(PlayerInfoBits_t info, Age_t age)
{
  assert(age >= PLAYER_AGE_MIN && age <= PLAYER_AGE_MAX);
  unsigned long long value = ((unsigned long long)age << PLAYER_AGE_OFFSET) & PLAYER_AGE_MASK;
  unsigned long long other = (info & ~PLAYER_AGE_MASK);  
  return (other | value); 
}

static inline TZ_t
Info_get_TZ(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_TZ_MASK;
  value = value >> PLAYER_TZ_OFFSET;
  return (TZ_t)value;
}

static inline PlayerInfoBits_t
Info_set_TZ(PlayerInfoBits_t info, TZ_t tz)
{
  assert(tz >= PLAYER_TZ_MIN && tz <= PLAYER_TZ_MAX);
  unsigned long long value = ((unsigned long long)tz << PLAYER_TZ_OFFSET) & PLAYER_TZ_MASK;
  unsigned long long other = (info & ~PLAYER_TZ_MASK);  
  return (other | value); 
}

static inline YBU_t
Info_get_YBU(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_YBU_MASK;
  value = value >> PLAYER_YBU_OFFSET;
  return (YBU_t)value;
}

static inline PlayerInfoBits_t
Info_set_YBU(PlayerInfoBits_t info, YBU_t ybu)
{
  assert(ybu >= PLAYER_YBU_MIN && ybu <= PLAYER_YBU_MAX);
  unsigned long long value = ((unsigned long long)ybu << PLAYER_YBU_OFFSET) & PLAYER_YBU_MASK;
  unsigned long long other = (info & ~PLAYER_YBU_MASK);  
  return (other | value); 
}

static inline Intl_t
Info_get_Intl(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_INTL_MASK;
  value = value >> PLAYER_INTL_OFFSET;
  return (Intl_t)value;
}

static inline PlayerInfoBits_t
Info_set_Intl(PlayerInfoBits_t info, Intl_t intl)
{
  assert(intl >= PLAYER_INTL_MIN && intl <= PLAYER_INTL_MAX);
  unsigned long long value = ((unsigned long long)intl << PLAYER_INTL_OFFSET) & PLAYER_INTL_MASK;
  unsigned long long other = (info & ~PLAYER_INTL_MASK);  
  return (other | value); 
}

static inline Dex_t
Info_get_Dex(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_DEX_MASK;
  value = value >> PLAYER_DEX_OFFSET;
  return (Dex_t)value;
}

static inline PlayerInfoBits_t
Info_set_Dex(PlayerInfoBits_t info, Dex_t dex)
{
  assert(dex >= PLAYER_DEX_MIN && dex <= PLAYER_DEX_MAX);
  unsigned long long value = ((unsigned long long)dex << PLAYER_DEX_OFFSET) & PLAYER_DEX_MASK;
  unsigned long long other = (info & ~PLAYER_DEX_MASK);  
  return (other | value); 
}

static inline Cha_t
Info_get_Cha(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_CHA_MASK;
  value = value >> PLAYER_CHA_OFFSET;
  return (Cha_t)value;
}

static inline PlayerInfoBits_t
Info_set_Cha(PlayerInfoBits_t info, Cha_t cha)
{
  assert(cha >= PLAYER_CHA_MIN && cha <= PLAYER_CHA_MAX);
  unsigned long long value = ((unsigned long long)cha << PLAYER_CHA_OFFSET) & PLAYER_CHA_MASK;
  unsigned long long other = (info & ~PLAYER_CHA_MASK);  
  return (other | value); 
}

static inline Hea_t
Info_get_Hea(PlayerInfoBits_t info)
{
  long long  h = info & PLAYER_HEA_MASK;

  // move value so most significant bit is all the way to the left
  h = h << (64 - ((PLAYER_HEA_OFFSET + PLAYER_HEA_LEN)));
  // replicate sign bit as we shift back down
  h = h >> (64 - PLAYER_HEA_LEN);
  return (int)h;
}

static inline PlayerInfoBits_t
Info_set_Hea(PlayerInfoBits_t info, Hea_t hea)
{
  assert(hea >= PLAYER_HEA_MIN && hea <= PLAYER_HEA_MAX);
  unsigned long long value = ((unsigned long long)hea << PLAYER_HEA_OFFSET) & PLAYER_HEA_MASK;
  unsigned long long other = (info & ~PLAYER_HEA_MASK);  
  return (other | value);
}

static inline BUID_t
Info_get_BUID(PlayerInfoBits_t info)
{
  PlayerInfoBits_t value = info & PLAYER_BUID_MASK;
  value = value >> PLAYER_BUID_OFFSET;
  return (BUID_t)value;
}

static inline PlayerInfoBits_t
Info_set_BUID(PlayerInfoBits_t info, BUID_t buid)
{
  assert(buid >= PLAYER_BUID_MIN && buid <= PLAYER_BUID_MAX);
  unsigned long long value = ((unsigned long long)buid << PLAYER_BUID_OFFSET) & PLAYER_BUID_MASK;
  unsigned long long other = (info & ~PLAYER_BUID_MASK);  
  return (other | value); 
}

static inline bool
Info_OnCampus(PlayerInfoBits_t info)
{
  return (info & (1ULL<<PLAYER_CAMPUS_OFFSET)) >> PLAYER_CAMPUS_OFFSET;
}

static inline PlayerInfoBits_t
Info_setOnCampus(PlayerInfoBits_t info)
{
  return (info | (1ULL<<PLAYER_CAMPUS_OFFSET));
}

static inline PlayerInfoBits_t
Info_clearOnCampus(PlayerInfoBits_t info)
{
  return (info & ~(1ULL<<PLAYER_CAMPUS_OFFSET));
}


static inline bool
Info_Awake(PlayerInfoBits_t info)
{
  return (info & (1ULL<<PLAYER_AWAKE_OFFSET)) >> PLAYER_AWAKE_OFFSET;
}

static inline PlayerInfoBits_t
Info_setAwake(PlayerInfoBits_t info)
{
  return (info | (1ULL<<PLAYER_AWAKE_OFFSET));
}

static inline PlayerInfoBits_t
Info_clearAwake(PlayerInfoBits_t info)
{
  return (info & ~(1ULL<<PLAYER_AWAKE_OFFSET));
}

static inline bool
Info_InClass(PlayerInfoBits_t info)
{
  return (info & (1ULL<<PLAYER_CLASS_OFFSET)) >> PLAYER_CLASS_OFFSET;
}

static inline PlayerInfoBits_t
Info_setInClass(PlayerInfoBits_t info)
{
  return (info | (1ULL<<PLAYER_CLASS_OFFSET));
}

static inline PlayerInfoBits_t
Info_clearInClass(PlayerInfoBits_t info)
{
  return (info & ~(1ULL<<PLAYER_CLASS_OFFSET));
}

static inline bool
Info_Partying(PlayerInfoBits_t info)
{
  return (info & (1ULL<<PLAYER_PARTY_OFFSET)) >> PLAYER_PARTY_OFFSET;
}

static inline PlayerInfoBits_t
Info_setPartying(PlayerInfoBits_t info)
{
  return (info | (1ULL<<PLAYER_PARTY_OFFSET));
}

static inline PlayerInfoBits_t
Info_clearPartying(PlayerInfoBits_t info)
{
  return (info & ~(1ULL<<PLAYER_PARTY_OFFSET));
}

static inline bool
Info_OnDate(PlayerInfoBits_t info)
{
  return (info & (1ULL<<PLAYER_DATE_OFFSET)) >> PLAYER_DATE_OFFSET;
}

static inline PlayerInfoBits_t
Info_setOnDate(PlayerInfoBits_t info)
{
  return (info | (1ULL<<PLAYER_DATE_OFFSET));
}

static inline PlayerInfoBits_t
Info_clearOnDate(PlayerInfoBits_t info)
{
  return (info & ~(1ULL<<PLAYER_DATE_OFFSET));
}

static inline bool
Info_DrinkingBeer(PlayerInfoBits_t info)
{
  return (info & (1ULL<<PLAYER_BEER_OFFSET)) >> PLAYER_BEER_OFFSET;
}

static inline PlayerInfoBits_t
Info_setDrinkingBeer(PlayerInfoBits_t info)
{
  return (info | (1ULL<<PLAYER_BEER_OFFSET));
}

static inline PlayerInfoBits_t
Info_clearDrinkingBeer(PlayerInfoBits_t info)
{
  return (info & ~(1ULL<<PLAYER_BEER_OFFSET));
}

#endif
