#include "Coin.h"
#include "Ball.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	CoinMesh->SetupAttachment(Root);
	//Set overlaping collision
	CoinMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	//RotationRate initialization for AddActorLocalRotation 
	RotationRate = 3.0f;

	//Register BeginOverlap Event
	OnActorBeginOverlap.AddDynamic(this, &ACoin::OnOverlap);
	
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
}

void ACoin::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ABall* BallVariable = Cast<ABall>(OtherActor);
	if (Cast<ABall>(OtherActor) != nullptr)
	{
		//Destroy current coin
		Destroy();
		BallVariable->CoinCounter--;
		//Call FinishLevel() from Ball.cpp if no more coins on level
		if (BallVariable->CoinCounter == 0)
		{
			BallVariable->FinishLevel();
		}
	}
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Add Rotation
	AddActorLocalRotation(FQuat(FRotator(0.0f, RotationRate, 0.0f)), false, nullptr, ETeleportType::None);
}

