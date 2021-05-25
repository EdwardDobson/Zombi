// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	Player = PC;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}
void ABullet::Move()
{
	FVector NewLocation = GetActorLocation() + (Speed * GetWorld()->DeltaTimeSeconds);
	SetActorLocation(NewLocation);

	//Player location
	//Mouse location
	//Player loc - Mouse loc = direction
}

