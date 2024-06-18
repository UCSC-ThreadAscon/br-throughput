#pragma once

#include "workload.h"
#include "time_api.h"

typedef enum PacketLossExpState
{
  NotStarted,
  Counting,
  DisplayedResults,
  Finished
} PacketLossExpState; 

typedef struct PacketLossStats
{
  struct timeval start;
  uint32_t nextSeqNumExpected;
  uint64_t packetsReceived;
  uint64_t packetsExpected;
  PacketLossExpState state;
}
PacketLossStats;

#define PrintDelimiter() otLogNotePlat("---------------------------");

#define PACKET_LOSS_DURATION_SECONDS 60
#define PACKET_LOSS_DURATION_US SECONDS_TO_US(PACKET_LOSS_DURATION_SECONDS)

void defaultRequestHandler(void* aContext,
                           otMessage *aMessage,
                           const otMessageInfo *aMessageInfo);

void throughputRequestHandler(void* aContext,
                              otMessage *aMessage,
                              const otMessageInfo *aMessageInfo);

void packetLossRequestHandler(void* aContext,
                              otMessage *aMessage,
                              const otMessageInfo *aMessageInfo);