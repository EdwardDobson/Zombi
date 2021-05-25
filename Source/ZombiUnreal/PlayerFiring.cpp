// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFiring.h"

// Sets default values for this component's properties
UPlayerFiring::UPlayerFiring()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	Player = PC;
}


// Called when the game starts
void UPlayerFiring::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UPlayerFiring::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (m_shouldReload)
	{
		Reloading();
	}
	if (m_shouldFire)
	{
		Fire(Player->GetActorLocation(),Player->GetActorRotation());
	}
}
void UPlayerFiring::SetWorld(UWorld* _world)
{
	World = _world;
}
void UPlayerFiring::Fire(const FVector _position,const FRotator _rotation)
{
	if (World != NULL)
	{
		if (Ammo > 0)
		{
			CurrentRateOfFire -= World->GetDeltaSeconds();
			if (CurrentRateOfFire <= 0)
			{
				World->SpawnActor<ABullet>(Bullet, _position, _rotation);
			
				CurrentRateOfFire = 0.4f;
				Ammo--;
			}

		}
	}
}

void UPlayerFiring::Reloading()
{
	CurrentReloadRate -= World->GetDeltaSeconds();
	if (CurrentReloadRate <= 0)
	{
		Ammo = 5;
		CurrentReloadRate = 0.5f;
		m_shouldReload = false;
	}
}
