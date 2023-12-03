#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  for(int i=0;i<nBatteries;i++)
    {
      
      double ratedCapacity=120.0;//rated capacity of new battery
      double presentCapacity =(double)presentCapacities[i];
      double stateOfHealth=(presentCapacity/ratedCapacity)*100;
      if(stateOfHealth>80){
        counts.healthy++;}
      else if (stateOfHealth <=80&& stateOfHealth>=62){
        counts.exchange++;}
      else{
        counts.failed++;
      }
    }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
