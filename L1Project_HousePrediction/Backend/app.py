from flask import Flask, request, jsonify
from flask_cors import CORS
import joblib  # or import pickle
import numpy as np

app = Flask(__name__)
CORS(app)

# Load your trained model
model = joblib.load('../../Notebook/best_xgb_model.pkl')
# Use pickle.load(open(...)) if you used pickle

@app.route('/predict', methods=['POST'])
# @app.route('/predict', methods=['POST'])
def predict():
    data = request.get_json()

    # Extract features
    bedrooms = data.get('bedrooms', 0)
    bathrooms = data.get('bathrooms', 0)
    living_area = data.get('living_area', 0)
    zipcode = data.get('zipcode', 0)
    location = data.get('location', '')

    # Arrange features in correct order your model expects
    # Example: [bedrooms, bathrooms, living_area, zipcode, location]
    # Adjust this line according to how your model was trained
    features = np.array([[bedrooms, bathrooms, living_area, int(zipcode)]])

    # Predict
    predicted_price = model.predict(features)[0]

    return jsonify({"predicted_price": round(predicted_price, 2)})


if __name__ == '__main__':
    app.run(debug=True)
