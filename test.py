import openai

API_KEY = "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" # Replace this with your API key

# Set up the OpenAI API client
openai.api_key = API_KEY

def get_models():
    try:
        models = openai.Model.list()
        available_models = [model.id for model in models["data"]]
        print("Models available to you:")
        for model in available_models:
            print(f"- {model}")

        required_models = [
            "gpt-4",
            "gpt-4-0314",
            "gpt-4-32k",
            "gpt-4-32k-0314"
        ]

        missing_models = [model for model in required_models if model not in available_models]
        if missing_models:
            print("\nYou are missing access to the following models:")
            for model in missing_models:
                print(f"- {model}")
        else:
            print("\nYou have access to all required models.")

    except Exception as e:
        print(f"Error: {e}")
        print("Unable to retrieve model information.")

if __name__ == "__main__":
    get_models()