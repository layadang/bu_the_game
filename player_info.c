#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "game_types.h"
#include "game_utils.h"
#include "player.h"

void
bprint(FILE *file, unsigned long long v, int start, int end)
{
  int highbit = (8*sizeof(v)-1);
  int i;
  unsigned long long highbitmask = (1ULL<<highbit);
  
  // FIXME: add sanity checking of arguments
  v = v << (highbit - end);
  for (i=start; i<=end; i++) {
    fputc((v & highbitmask) ? '1' : '0', file);
    v=v<<1;
  }
}

void Info_print(PlayerInfoBits_t info, FILE *file)
{

  fprintf(file, "info: %llx : ", info);
  bprint(file, info, 0, 63);
  fprintf(file,"\n");
  
  fprintf(file, "age:\t%u\t[", Info_get_Age(info));
  bprint(file, info, PLAYER_AGE_OFFSET, PLAYER_AGE_OFFSET + PLAYER_AGE_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "tz:\t%u\t[", Info_get_TZ(info));
  bprint(file, info, PLAYER_TZ_OFFSET, PLAYER_TZ_OFFSET + PLAYER_TZ_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "ybu:\t%u\t[", Info_get_YBU(info));
  bprint(file, info, PLAYER_YBU_OFFSET, PLAYER_YBU_OFFSET + PLAYER_YBU_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "intl:\t%u\t[", Info_get_Intl(info));
  bprint(file, info, PLAYER_INTL_OFFSET, PLAYER_INTL_OFFSET + PLAYER_INTL_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "dex:\t%u\t[", Info_get_Dex(info));
  bprint(file, info, PLAYER_DEX_OFFSET, PLAYER_DEX_OFFSET + PLAYER_DEX_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "cha:\t%u\t[", Info_get_Cha(info));
  bprint(file, info, PLAYER_CHA_OFFSET, PLAYER_CHA_OFFSET + PLAYER_CHA_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "hea:\t%d\t[", Info_get_Hea(info));
  bprint(file, info, PLAYER_HEA_OFFSET, PLAYER_HEA_OFFSET + PLAYER_HEA_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "buid:\t%u\t[", Info_get_BUID(info));
  bprint(file, info, PLAYER_BUID_OFFSET, PLAYER_BUID_OFFSET + PLAYER_BUID_LEN-1);
  fprintf(file, "]\n");

  fprintf(file, "campus:\t%u\t[", Info_OnCampus(info));
  bprint(file, info, PLAYER_CAMPUS_OFFSET, PLAYER_CAMPUS_OFFSET);
  fprintf(file, "]\n");

  fprintf(file, "awake:\t%u\t[", Info_Awake(info));
  bprint(file, info, PLAYER_AWAKE_OFFSET, PLAYER_AWAKE_OFFSET);
  fprintf(file, "]\n");

  fprintf(file, "class:\t%u\t[", Info_InClass(info));
  bprint(file, info, PLAYER_CLASS_OFFSET, PLAYER_CLASS_OFFSET);
  fprintf(file, "]\n");

  fprintf(file, "party:\t%u\t[", Info_Partying(info));
  bprint(file, info, PLAYER_PARTY_OFFSET, PLAYER_PARTY_OFFSET);
  fprintf(file, "]\n");

  fprintf(file, "date:\t%u\t[", Info_OnDate(info));
  bprint(file, info, PLAYER_DATE_OFFSET, PLAYER_DATE_OFFSET);
  fprintf(file, "]\n");

  fprintf(file, "beer:\t%u\t[", Info_DrinkingBeer(info));
  bprint(file, info, PLAYER_BEER_OFFSET, PLAYER_BEER_OFFSET);
  fprintf(file, "]\n");
}

