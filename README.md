# Miernik_Rezystancji_ESP32

Projekt embedded do pomiaru rezystancji z wykorzystaniem przetwornika ADC oraz dzielnika napięcia wraz z filtracją sygnału poprzez średnią kroczącą(SMA).

---

## Cel projektu

Celem było:

* zaprojektowanie prostego układu pomiarowego
* implementacja algorytmu obliczania rezystancji
* poprawa stabilności pomiarów poprzez filtrację danych
* analiza ograniczeń pomiarowych ADC

---

## Technologie

* C / Arduino
* ADC (analogReadMilliVolts)
* UART (Serial)
* podstawy przetwarzania sygnałów

---

## Zasada działania

Układ oparty jest o dzielnik napięcia:

```
Vin ── R1 ──┬── Vout (ADC)
            │
           R2
            │
           GND
```

Rezystancja obliczana jest ze wzoru:

```
R = (Vout * R1) / (Vin - Vout)
```

---

## Filtracja sygnału

Zastosowano:

* **Simple Moving Average (SMA)**
* okno: 10 próbek

Cel:

* redukcja szumu ADC
* stabilizacja wyniku

Uwagi:

* filtr wprowadza opóźnienie

---

## Problemy i rozwiązania

### 1. Szum pomiarowy ADC

**Problem:**
niestabilne odczyty napięcia

**Rozwiązanie:**

* filtr SMA
* uśrednianie wielu próbek

## Przykładowy wynik dla R2 ≈ 1200 ± 5% z filtrem SMA

```
Rezystancja wynosi: 1228.55Ω
Rezystancja wynosi: 1232.93Ω
```
## Przykładowy wynik dla R2 ≈ 1200 ± 5% bez filtra SMA
```
Rezystancja wynosi: 1190.78Ω
Rezystancja wynosi: 1251.78Ω
```

## Ograniczenia

* dokładność zależna od:

  * tolerancji R1
  * stabilności Vin
  * rozdzielczości ADC

---

## Możliwe rozszerzenia

* Exponential Moving Average
* kalibracja napięcia referencyjnego
* wyświetlacz (OLED / LCD)
* zapis do pliku

---

