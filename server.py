from flask import Flask, request
import subprocess

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        user_input = request.form.get("password")
        user_path = r"C:\DPUSEC\dpusec.exe"
        # C programını çalıştır ve çıktısını al
        result = subprocess.run([user_path, user_input], capture_output=True, text=True)

        # Sonucu web arayüzüne gönder
        return f"""
            <h2>Debug Output</h2>
            <pre>{result.stdout}</pre>
            <br><a href="/">Try Again</a>
        """

    return '''
        <h2>Login</h2>
        <form method="post">
            <input name="password" type="text" />
            <input type="submit" value="Gönder" />
        </form>
    '''

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
