#include "CPPTrainingEditor.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"


IMPLEMENT_GAME_MODULE(FCPPTrainingEditorModule, CPPTrainingEditor);

void FCPPTrainingEditorModule::StartupModule()
{
	// Check if editor is valid
	if (GUnrealEd)
	{
		// Registering the move visualizer
		TSharedPtr<FMoveComponentVisualizer> MoveVisualizer = MakeShareable(new FMoveComponentVisualizer);

		if (MoveVisualizer.IsValid())
		{
			GUnrealEd->RegisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName(), MoveVisualizer);
			MoveVisualizer->OnRegister();
		}		
	}
}

void FCPPTrainingEditorModule::ShutdownModule()
{
	// Check if editor is valid
	if (GUnrealEd)
	{
		GUnrealEd->UnregisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName());
	}
}