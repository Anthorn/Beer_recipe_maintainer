#include <equipment.h>
#include <string>
#include <iostream>


void Equipment::setName(string name){
  name = name;
}

void Equipment::setVersion(string version){
  version = version;
}

void Equipment::setBatchSize(double batchSize){
  batchSize = batchSize;
}

void Equipment::setBoilSize(double boilSize){
  boilSize = boilSize;
}

void Equipment::setBoilTime(double boilTime){
  boilTime = boilTime;
}

void Equipment::setEfficency(double efficeny){
  efficency = efficency;
}

void Equipment::setTunVolume(double tunVolume){
  tunVolume = tunVolume;
}

void Equipment::setTrubChillerLoss(double trubLoss){
  trubChillerLoss = trubLoss;
}

void Equipment::setEvaporationRate(double evapRate){
  evaporationRate = evapRate;
}

void Equipment::setHopUtilization(double hopUtil){
  hopUtil = hopUtil;
}

void Equipment::setLauterDeadspace(double lauterDeadspace){
  lauterDeadspace = lauterDeadspace;
}
