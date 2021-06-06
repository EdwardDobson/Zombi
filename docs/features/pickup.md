## Overview

To create the pickup feature I used a combination of C++ code and blueprints. When the player hits the pickup a value will be changed based on its type this is done in the C++ code. The animation for the blobbing and turning is done via blueprints.

## Implementation.

### Interaction
<pre><code>
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
void AHealthPickup::SpawnParticle()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, GetActorLocation());
}
</code></pre>
### Animation

![Healthpickup Animation](https://user-images.githubusercontent.com/47003895/120931622-4eb40680-c6ea-11eb-912c-2135d33f3a34.png)

[Here](https://blueprintue.com/blueprint/xmufu0s6/) is a link to copy the blueprint.
