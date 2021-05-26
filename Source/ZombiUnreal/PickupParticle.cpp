

#include "PickupParticle.h"

// Sets default values
APickupParticle::APickupParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupParticle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

