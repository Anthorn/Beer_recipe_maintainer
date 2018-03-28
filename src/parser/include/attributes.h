#ifndef DEF_ATTRIBUTES_H
#define DEF_ATTRIBUTES_H

#include <string>

#define BEER_ATTRIBUTE_SIZE 10
#define HOP_ATTRIBUTE_SIZE 10
#define FERMENTABLE_ATTRIBUTE_SIZE 10
#define YEAST_ATTRIBUTE_SIZE 14
#define WATER_ATTRIBUTE_SIZE 11
#define STYLE_ATTRIBUTE_SIZE 11
#define EQUIP_ATTRIBUTE_SIZE 11
#define MASH_STEP_ATTR_SIZE  9
#define MASH_META_DATA_ATTR_SIZE 4

using namespace std;

static string beerDataAttributes[BEER_ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "BREWER",
  "BATCH_SIZE",
  "BOIL_SIZE",
  "BOIL_TIME",
  "EFFICIENCY",
  "ABV",
  "EST_ABV"};

static string hopAttributes[HOP_ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "ORIGIN",
  "ALPHA",
  "USE",
  "TIME",
  "NOTES",
  "TYPE",
  "FORM",
  "AMOUNT"};

static string fermentableAttributes[FERMENTABLE_ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "AMOUNT",
  "YIELD",
  "COLOR",
  "ADD_AFTER_BOIL",
  "ORIGIN",
  "NOTES",
  "RECOMMEND_MASH"};

static string yeastAttributes[YEAST_ATTRIBUTE_SIZE] = {
  "NAME",
  "VERSION",
  "TYPE",
  "FORM",
  "AMOUNT",
  "AMOUNT_IS_WEIGHT",
  "LABORATORY",
  "PRODUCT_ID",
  "MIN_TEMPERATURE",
  "MAX_TEMPERATURE",
  "FLOCCULATION",
  "ATTENUATION",
  "NOTES",
  "CULTURE_DATE"};

static string waterAttributes[WATER_ATTRIBUTE_SIZE] = {
  "NAME",
  "VERSION",
  "AMOUNT",
  "CALCIUM",
  "BICARBONATE",
  "SULFATE",
  "CHLORIDE",
  "SODIUM",
  "MAGNESIUM",
  "PH",
  "NOTES"};

static string styleAttributes[STYLE_ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "CATEGORY",
  "NOTES",
  "ABV_MAX",
  "ABV_MIN",
  "COLOR_MAX",
  "COLOR_MIN",
  "IBU_MAX",
  "IBU_MIN"};

static string equipmentAttributes[EQUIP_ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "BOIL_SIZE",
  "BATCH_SIZE",
  "TUN_VOLUME",
  "TRUB_CHILLER_LOSS",
  "EVAP_RATE",
  "BOIL_TIME",
  "LAUTER_DEADSPACE",
  "HOP_UTILIZATION",
  "NOTES"};

static string mashMetaDataAttr[MASH_META_DATA_ATTR_SIZE] =  {
  "NAME",
  "VERSION",
  "SPARGE_TEMP",
  "PH"};

static string mashStepAttr[MASH_STEP_ATTR_SIZE] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "INFUSE_AMOUNT",
  "STEP_TIME",
  "STEP_TEMP",
  "END_TEMP",
  "WATER_GRAIN_RATIO",
  "INFUSE_TEMP"};

#endif
