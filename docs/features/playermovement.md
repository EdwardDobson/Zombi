## Overview

The player movement is one of the core elements in my project and was written in C++.
The current velocity is applied to the players current location this moves the player. Both the left and right functions are bound to the two axis set in the project settings. I use delta time to make sure that the framerate wont affect the players speed.

### Implementation

<pre><code>void ABasePlay::MoveUp(float _value)
{
	CurrentVelocity.X = FMath::Clamp(_value, -1.0f, 1.0f) * MovementForce;
}
void ABasePlay::MoveRight(float _value)
{
	CurrentVelocity.Y = FMath::Clamp(_value, -1.0f, 1.0f) * MovementForce;
}
void ABasePlay::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveUp", this, &ABasePlay::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlay::MoveRight);
}
if (!CurrentVelocity.IsZero())
{
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);
}
</code></pre>
