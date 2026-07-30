import tkinter as tk
from tkinter import messagebox
import time
import threading

from chatbot_logic import ChatbotLogic


# Create chatbot logic object
chatbot = ChatbotLogic()


def send_message():
    """
    Gets user input, displays it, gets chatbot response, and speaks the response.
    """
    user_input = entry.get()
    response = chatbot.get_response(user_input)
    timestamp = time.strftime("%H:%M")

    chat_log.insert(tk.END, f"You ({timestamp}): {user_input}\n", "user")
    chat_log.insert(tk.END, f"Bot ({timestamp}): {response}\n\n", "bot")

    chatbot.speak(response)

    entry.delete(0, tk.END)


def save_chat_log():
    """
    Saves the current chat conversation.
    """
    content = chat_log.get("1.0", tk.END)

    with open("chat_log.txt", "w", encoding="utf-8") as file:
        file.write(content)

    messagebox.showinfo("Saved", "Chat log saved successfully.")


def clear_chat():
    """
    Clears the chat screen and resets chatbot memory.
    """
    chat_log.delete("1.0", tk.END)
    chatbot.clear_memory()


def exit_app():
    """
    Closes the application.
    """
    root.destroy()


# Main window
root = tk.Tk()
root.title("In-Store FAQ Chatbot")
root.geometry("700x500")
root.configure(bg="#f0f2f5")


# Header
header = tk.Label(
    root,
    text="In-Store FAQ Chatbot",
    font=("Helvetica", 16, "bold"),
    bg="#f0f2f5",
    fg="#0f172a"
)
header.pack(pady=10)


# Chat frame
frame = tk.Frame(root, bg="#f0f2f5")
frame.pack(padx=10, pady=5)


# Scrollbar
scrollbar = tk.Scrollbar(frame)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)


# Chat display
chat_log = tk.Text(
    frame,
    height=20,
    width=85,
    yscrollcommand=scrollbar.set,
    bg="white",
    fg="black",
    font=("Arial", 10)
)
chat_log.pack(side=tk.LEFT, fill=tk.BOTH)

scrollbar.config(command=chat_log.yview)


# Message colours
chat_log.tag_config("user", foreground="blue")
chat_log.tag_config("bot", foreground="green")


# Entry field
entry = tk.Entry(root, width=70, font=("Arial", 11))
entry.pack(pady=10)


# Button frame
button_frame = tk.Frame(root, bg="#f0f2f5")
button_frame.pack()


send_button = tk.Button(
    button_frame,
    text="Send",
    width=12,
    bg="#16a34a",
    fg="white",
    font=("Arial", 10, "bold"),
    command=send_message
)
send_button.grid(row=0, column=0, padx=5)


clear_button = tk.Button(
    button_frame,
    text="Clear",
    width=12,
    bg="#64748b",
    fg="white",
    font=("Arial", 10),
    command=clear_chat
)
clear_button.grid(row=0, column=1, padx=5)


save_button = tk.Button(
    button_frame,
    text="Save Chat",
    width=12,
    bg="#0891b2",
    fg="white",
    font=("Arial", 10),
    command=save_chat_log
)
save_button.grid(row=0, column=2, padx=5)


exit_button = tk.Button(
    button_frame,
    text="Exit",
    width=12,
    bg="#ef4444",
    fg="white",
    font=("Arial", 10),
    command=exit_app
)
exit_button.grid(row=0, column=3, padx=5)


# Start application
root.mainloop()