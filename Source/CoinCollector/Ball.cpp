#include "Ball.h"
#include "Coin.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	//Set Physics
	Mesh->SetSimulatePhysics(true);
	Mesh->GetBodyInstance()->SetMassOverride(400.0f, true);
	Mesh->SetLinearDamping(0.5f);
	Mesh->SetAngularDamping(0.1f);
	
	// WidgetClass variable initialization
	ConstructorHelpers::FClassFinder<UUserWidget> LevelCompleteWidget(TEXT("/Game/CoinCollector/UI/W_LevelComplete"));
	if (!ensure(LevelCompleteWidget.Class != nullptr))
		return;
	LevelCompleteWidgetClass = LevelCompleteWidget.Class;
}
// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	//Get number of coin on level
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACoin::StaticClass(), CoinActorsArray);
	CoinCounter = CoinActorsArray.Num();
}
// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Blue, FString::FromInt(CoinCounter));
}
//Called from Coin.cpp when we colect last coin
void ABall::FinishLevel()
{
	// Disable input
	GetWorld()->GetFirstPlayerController()->SetPause(true);

	// Show LevelCompleteUI
	UUserWidget* GameOver = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), LevelCompleteWidgetClass);
	GameOver->AddToViewport();

	// Enable cursor
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

