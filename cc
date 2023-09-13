static async Task Main()
{
    string apiKey = "YOUR_API_KEY";
    string fromCurrency = "USD";
    string toCurrency = "EUR";

    HttpClient client = new HttpClient();
    HttpResponseMessage response = await client.GetAsync($"https://v6.exchangeratesapi.io/latest?access_key={apiKey}&base={fromCurrency}");
    string json = await response.Content.ReadAsStringAsync();

    JObject rates = JObject.Parse(json)["rates"] as JObject;
    decimal exchangeRate = (decimal)rates[toCurrency];

    Console.WriteLine($"1 {fromCurrency} = {exchangeRate} {toCurrency}");
}
