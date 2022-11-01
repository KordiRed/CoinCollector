#include "Surface.h"
// Sets default values
ASurface::ASurface()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = Mesh;
	Camera->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ASurface::BeginPlay()
{
	Super::BeginPlay();
}

//Set UpDown 12 degrees incline of surface
void ASurface::RotateUpDown(float AxisValue)
{
	FRotator rotator = GetActorRotation();
	rotator.Pitch = FMath::GetMappedRangeValueClamped(FVector2D(-1, 1), FVector2D(-12, 12), AxisValue);
	//For a smooth incline
	AActor::SetActorRotation(FMath::RInterpTo(GetActorRotation(), rotator, 0.01, 3.2));
}
//Set LeftRight 12 degrees incline of surface
void ASurface::RotateLeftRight(float AxisValue)
{
	FRotator rotator = GetActorRotation();
	rotator.Roll = FMath::GetMappedRangeValueClamped(FVector2D(-1, 1), FVector2D(-12, 12), AxisValue);
	//For a smooth incline
	AActor::SetActorRotation(FMath::RInterpTo(GetActorRotation(), rotator, 0.01, 3.2));
}

// Called to bind functionality to input
void ASurface::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("RotateUpDown", this, &ASurface::RotateUpDown);
	PlayerInputComponent->BindAxis("RotateLeftRight", this, &ASurface::RotateLeftRight);
	
}

