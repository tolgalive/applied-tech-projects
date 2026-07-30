import json
import subprocess


class ChatbotLogic:
    def __init__(self, faq_file="faq_data.json"):
        self.faq_file = faq_file
        self.faq_data = self.load_faq_data()
        self.asked_questions = set()

    def load_faq_data(self):
        with open(self.faq_file, "r", encoding="utf-8") as file:
            return json.load(file)

    def speak(self, text):
        """
        Speaks the chatbot response using Windows built-in speech system.
        This avoids pyttsx3 speaking only once.
        """
        try:
            safe_text = text.replace("'", "")
            command = (
                "Add-Type -AssemblyName System.Speech; "
                "$speaker = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
                f"$speaker.Speak('{safe_text}');"
            )

            subprocess.Popen(
                ["powershell", "-Command", command],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL
            )

        except Exception as error:
            print("Speech error:", error)

    def get_response(self, user_input):
        user_input = user_input.lower().strip()

        if user_input == "":
            return "Please type a question."

        if user_input in self.asked_questions:
            return "You've already asked this question. Would you like to ask something else?"

        self.asked_questions.add(user_input)

        for item in self.faq_data:
            for keyword in item["keywords"]:
                if keyword.lower() in user_input:
                    return item["response"]

        return "I'm sorry, I didn't understand that. Please ask something else."

    def clear_memory(self):
        self.asked_questions.clear()