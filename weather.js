const axios = require('axios');

// Replace with your MapTiler API key
const MAPTILER_API_KEY = 'i03c3LRZqPUzSX7bxzju';
const CITY = 'New York';

// Step 1: Use MapTiler Geocoding API to get coordinates of New York City
const geocodeURL = `https://api.maptiler.com/geocoding/${encodeURIComponent(CITY)}.json?key=${MAPTILER_API_KEY}`;

async function getCoordinates() {
  try {
    const response = await axios.get(geocodeURL);
    const data = response.data;

    if (data.features && data.features.length > 0) {
      const { center } = data.features[0]; // Coordinates [longitude, latitude]
      return { lon: center[0], lat: center[1] };
    } else {
      throw new Error('No location found for the specified city.');
    }
  } catch (error) {
    console.error('Error fetching geocoding data from MapTiler:', error.message);
    return null;
  }
}

// Step 2: Fetch weather data using coordinates from MetaWeather
async function getWeather(lat, lon) {
  // MetaWeather URL to get WOEID (Where On Earth ID) for the location
  const woeidURL = `https://www.metaweather.com/api/location/search/?lattlong=${lat},${lon}`;

  try {
    const response = await axios.get(woeidURL);
    const data = response.data;

    if (data.length > 0) {
      const woeid = data[0].woeid;
      // MetaWeather URL to fetch weather details using WOEID
      const weatherURL = `https://www.metaweather.com/api/location/${woeid}/`;

      const weatherResponse = await axios.get(weatherURL);
      const weatherData = weatherResponse.data;

      // Extract relevant weather details
      const weatherDetails = {
        city: weatherData.title,
        temperature: weatherData.consolidated_weather[0].the_temp,
        description: weatherData.consolidated_weather[0].weather_state_name,
        humidity: weatherData.consolidated_weather[0].humidity,
        windSpeed: weatherData.consolidated_weather[0].wind_speed,
      };

      console.log('Weather Details for New York City:', weatherDetails);
    } else {
      throw new Error('No location found for the specified coordinates.');
    }
  } catch (error) {
    console.error('Error fetching weather data from MetaWeather:', error.message);
  }
}

// Main function to orchestrate the steps
async function main() {
  const coordinates = await getCoordinates();
  if (coordinates) {
    await getWeather(coordinates.lat, coordinates.lon);
  }
}

main();
