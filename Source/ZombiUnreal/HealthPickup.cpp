// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthPickup.h"
#include "BasePlay.h"
// Sets default values
AHealthPickup::AHealthPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this, &AHealthPickup::OnOverlap);

}

void AHealthPickup::SpawnParticle()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, GetActorLocation());
}

// Called when the game starts or when spawned
void AHealthPickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AHealthPickup::OnOverlap(AActor *_this, AActor *_other)
{
	if (Cast<ABasePlay>(_other) != nullptr)
	{
		if (DamagePlayer)
		{
			Cast<ABasePlay>(_other)->Damage(Value);
			SpawnParticle();
			Destroy();
		}
		else
		{
			Cast<ABasePlay>(_other)->IncreasePlayerHealth(Value);
			SpawnParticle();
			Destroy();
		}
	}
}
