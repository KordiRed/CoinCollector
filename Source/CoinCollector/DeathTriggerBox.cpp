#include "DeathTriggerBox.h"

ADeathTriggerBox::ADeathTriggerBox()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &ADeathTriggerBox::OnOverlapBegin);
    

    // WidgetClass variable initialization
    ConstructorHelpers::FClassFinder<UUserWidget> GameOverWidget(TEXT("/Game/CoinCollector/UI/W_GameOver"));
    if (!ensure(GameOverWidget.Class != nullptr))
        return;
    GameOverWidgetClass = GameOverWidget.Class;
}

// Called when the game starts or when spawned
void ADeathTriggerBox::BeginPlay()
{
    Super::BeginPlay();
}

void ADeathTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    // Check if Actors do not equal nullptr
    if (OtherActor && (OtherActor != this)) 
    {

        // Disable input
        GetWorld()->GetFirstPlayerController()->SetPause(true);

        // Show DeathUI
        UUserWidget* GameOver = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), GameOverWidgetClass);
        GameOver->AddToViewport();

        // Enable cursor
        GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;   
    }
}

