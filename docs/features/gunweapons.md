# Overview

The gun class allows the easy creation of different types of guns. This was solely written in C++, at the start of the game the current values get set this saves having to match the current ammo with the max ammo for example.
## Implementation

<pre><code>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxReloadTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxFireRateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
	float FireRate;
	float ReloadTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString GunName;
void AGunWeapon::BeginPlay()
{
	Super::BeginPlay();
	Ammo = MaxAmmo;
	FireRate = MaxFireRateTime;
	ReloadTime = MaxReloadTime;
}
</code></pre>
