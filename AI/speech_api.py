# pip install SpeechRecognition pyaudio gtts
import speech_recognition as sr
from gtts import gTTS
import os

recognizer = sr.Recognizer()

# Function to capture speech and recognize it using Google Web Speech API
def recognize_speech_from_mic():
    with sr.Microphone() as source:
        # Adjust for ambient noise quickly to minimize initial delay
        recognizer.adjust_for_ambient_noise(source, duration=0.5)  # Minimal delay for noise adjustment

        # Set pause threshold to 2 seconds of silence to wait for speech completion
        recognizer.pause_threshold = 1  # Wait for 2 seconds of blankness before considering the input finished

        print("Listening for speech...")
        audio_data = recognizer.listen(source, timeout=None)  # Listen without a timeout limit

    # Recognize the captured speech using Google Web Speech API
    try:
        print("Recognizing speech...")
        text = recognizer.recognize_google(audio_data)
        print("You said: " + text)
        tts = gTTS(text=text, lang='en', slow=False)
        tts.save("output.mp3")
        os.system("start output.mp3")
    except sr.UnknownValueError:
        print("Sorry, I could not understand the audio.")
    except sr.RequestError as e:
        print(f"Could not request results from Google Web Speech API; {e}")

recognize_speech_from_mic()
