# BLESpam ライブラリ

Arduino用のBluetooth Low Energy (BLE) スパムライブラリです。ESP32やnRF52などのBLE対応マイコンで使用できます。

## 特徴

- 🍎 **Apple Continuity** - iOS端末に「新しいデバイス」ポップアップを表示（AirPods、Beatsなど）
- 🪟 **Microsoft Swift Pair** - Windows端末にペアリングプロンプトを表示
- 📱 **Samsung Easy Setup** - Samsung端末にペアリングダイアログを表示
- ⚡ **使いやすい** - 最小限のコードで動作
- 🎯 **カスタマイズ可能** - 広告間隔、送信電力、MACアドレスを調整可能
- 🔧 **Arduino対応** - Arduino IDEおよびPlatformIOで動作

## 対応プラットフォーム

- **ESP32** (ESP32, ESP32-S3, ESP32-C3など) - 完全対応
- **nRF52** シリーズ - 近日対応予定
- その他のBLE対応マイコン - 近日対応予定

## インストール

### Arduino IDE

1. [GitHubリリース](https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon/releases)から最新版をダウンロード
2. Arduino IDEで、**スケッチ → ライブラリをインクルード → .ZIP形式のライブラリをインストール**を選択
3. ダウンロードしたZIPファイルを選択

### PlatformIO

`platformio.ini`に以下を追加:

```ini
lib_deps = 
    https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon.git
```

### 手動インストール

1. このリポジトリをクローンまたはダウンロード
2. `BLESpamLibrary`フォルダをArduinoライブラリディレクトリにコピー:
   - Windows: `Documents\Arduino\libraries\`
   - Mac: `~/Documents/Arduino/libraries/`
   - Linux: `~/Arduino/libraries/`

## クイックスタート

### 基本的なAppleデバイススパム

```cpp
#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    Serial.begin(115200);
    
    // BLE初期化
    bleSpam.begin("ESP32-BLE");
    
    // パラメータ設定
    bleSpam.setAdvertisingInterval(100); // 100ms
    bleSpam.setTxPower(3);               // 3 dBm
    
    // AirPods Proの広告開始
    bleSpam.advertiseAppleDevice(AIRPODS_PRO);
}

void loop() {
    // 動作継続
    delay(1000);
}
```

### Windows Swift Pair

```cpp
#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    bleSpam.begin("ESP32-Swift");
    bleSpam.advertiseWindowsSwiftPair();
}

void loop() {
    delay(1000);
}
```

## API リファレンス

### 初期化

#### `bool begin(const char* deviceName = "BLE Spam")`

BLEスパムライブラリを初期化します。

- **パラメータ:**
  - `deviceName`: Bluetoothデバイス名（オプション）
- **戻り値:** 成功時は`true`、失敗時は`false`

#### `void stop()`

BLE広告を停止します。

### Appleデバイス

#### `void advertiseAppleDevice(AppleDeviceType deviceType)`

iOS端末に「新しいデバイス」ポップアップを表示するためのAppleデバイスを広告します。

**対応Appleデバイス:**
- `AIRPODS_PRO` - AirPods Pro
- `AIRPODS_MAX` - AirPods Max
- `AIRPODS` - AirPods (第1世代)
- `AIRPODS_GEN2` - AirPods (第2世代)
- `AIRPODS_GEN3` - AirPods (第3世代)
- `AIRPODS_PRO_GEN2` - AirPods Pro (第2世代)
- `BEATS_FLEX` - Beats Flex
- `BEATS_SOLO3` - Beats Solo 3
- `POWERBEATS3` - Powerbeats 3
- `POWERBEATS_PRO` - Powerbeats Pro
- その他多数

### Windowsデバイス

#### `void advertiseWindowsSwiftPair()`

Windows端末にペアリングプロンプトを表示するためのMicrosoft Swift Pairを広告します。

### Samsungデバイス

#### `void advertiseSamsungEasySetup(const char* model = "Buds")`

Samsung端末にペアリングダイアログを表示するためのSamsung Easy Setupを広告します。

### 設定

#### `void setAdvertisingInterval(uint16_t intervalMs)`

BLE広告間隔を設定します。

- **パラメータ:**
  - `intervalMs`: ミリ秒単位の間隔（20-10240、デフォルト: 100）

#### `void setTxPower(int8_t powerDbm)`

送信電力レベルを設定します。

- **パラメータ:**
  - `powerDbm`: dBm単位の電力（ESP32: -12, -9, -6, -3, 0, 3, 6, 9）

#### `void setRandomMac(bool enable)`

ランダムMACアドレスを有効/無効にします。

## サンプルスケッチ

ライブラリには以下のサンプルスケッチが含まれています:

1. **AppleBLESpam** - 様々なAppleデバイスを順番に広告
2. **WindowsSwiftPair** - Windows Swift Pairを広告
3. **SamsungEasySetup** - Samsung Easy Setupを広告
4. **AllDevicesSpam** - すべてのスパムタイプを順番に実行
5. **RandomAppleSpam** - ランダムなAppleデバイスを可変間隔で広告

## ハードウェア要件

### ESP32

- BLE対応のESP32ボード
- 推奨: ESP32-DevKitC, ESP32-WROOM, ESP32-S3

### 電源

- USB電源: USBから5V
- バッテリー: 3.3V LiPoバッテリー（適切な電圧レギュレータ付き）

## 通信距離

有効距離は以下の要因に依存します:

- **送信電力レベル**: 高電力 = 長距離
- **アンテナ**: 内蔵アンテナ vs 外部アンテナ
- **環境**: 障害物、干渉など

一般的な距離:
- 屋内: 10-30メートル
- 屋外: 30-100メートル（高送信電力時）

## 法的および倫理的な考慮事項

⚠️ **重要な免責事項** ⚠️

このライブラリは**教育および研究目的のみ**で提供されています。

- このツールは、近くのデバイスに不要なポップアップを表示させるBLE広告を作成します
- このライブラリの使用は一部の法域で違法となる可能性があります
- 他者を嫌がらせ、迷惑をかけ、または危害を加えるためにこのライブラリを使用することは非倫理的であり、違法である可能性があります
- 所有していないデバイスでテストする前に、必ず許可を得てください
- 著者はこのライブラリの誤用に対して責任を負いません

**責任を持って倫理的に使用してください。**

## クレジット

このライブラリは以下に基づいています:

- [Bluetooth LE Spam Android App](https://github.com/simondankelmann/Bluetooth-LE-Spam) by Simon Dankelmann
- [Flipper Zero BLE Spam](https://github.com/Willy-JL/Flipper-XTREME)の貢献
- furiousMAC、Hexwayなどの研究

BLEセキュリティコミュニティのすべての貢献者と研究者に感謝します。

## ライセンス

このプロジェクトはGPL-3.0ライセンスの下でライセンスされています - 詳細は[LICENSE](../LICENSE)ファイルを参照してください。

## 貢献

貢献を歓迎します！プルリクエストを送信してください。

## サポート

問題、質問、貢献については:
- GitHub Issues: [問題を報告](https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon/issues)
- Discussions: [ディスカッションに参加](https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon/discussions)

## 変更履歴

### バージョン 1.0.0 (初回リリース)
- Apple Continuityサポート（17デバイスタイプ）
- Microsoft Swift Pairサポート
- Samsung Easy Setupサポート
- ESP32プラットフォームサポート
- 基本的なサンプルとドキュメント
