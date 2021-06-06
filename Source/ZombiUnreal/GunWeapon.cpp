// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlay.h"
#include "GunWeapon.h"
// Sets default values
AGunWeapon::AGunWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ammo = MaxAmmo;
}

// Called when the game starts or when spawned
void AGunWeapon::BeginPlay()
{
	Super::BeginPlay();
	Ammo = MaxAmmo;
	FireRate = MaxFireRateTime;
	ReloadTime = MaxReloadTime;
}

// Called every frame
void AGunWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


