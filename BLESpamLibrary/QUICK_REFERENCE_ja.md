# BLESpam ライブラリ - クイックリファレンス

> [日本語版](QUICK_REFERENCE_ja.md) | [English](QUICK_REFERENCE.md)

## インストール クイックスタート

### Arduino IDE
1. GitHubからZIPをダウンロード
2. スケッチ → ライブラリをインクルード → .ZIP形式のライブラリをインストール
3. ZIPファイルを選択

### PlatformIO
`platformio.ini`に追加:
```ini
lib_deps = https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon.git
```

## ハードウェアセットアップ

### ESP32ボード
- ESP32-DevKitC ✅
- ESP32-WROOM ✅
- ESP32-S3 ✅
- ESP32-C3 ✅

### 配線
- プログラミングと電源用のUSBケーブル
- オプション: より長い通信距離のための外部アンテナ

## 基本的な使用パターン

```cpp
#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    bleSpam.begin("DeviceName");           // 初期化
    bleSpam.setAdvertisingInterval(100);   // 間隔設定
    bleSpam.setTxPower(3);                 // 電力設定
    bleSpam.advertiseAppleDevice(AIRPODS_PRO); // スパム開始
}

void loop() {
    delay(1000); // 動作継続
}
```

## スパムタイプ

### Appleデバイス
```cpp
bleSpam.advertiseAppleDevice(AIRPODS_PRO);
bleSpam.advertiseAppleDevice(BEATS_STUDIO_BUDS);
bleSpam.advertiseAppleDevice(AIRPODS_MAX);
// ... 合計17種類のデバイスタイプ
```

### Windows
```cpp
bleSpam.advertiseWindowsSwiftPair();
```

### Samsung
```cpp
bleSpam.advertiseSamsungEasySetup("Buds");
```

## 設定オプション

### 広告間隔
```cpp
bleSpam.setAdvertisingInterval(100); // 100ms（速い = より多くのスパム）
```
- 範囲: 20-10240 ms
- 低い値 = より頻繁だが消費電力が高い
- 推奨: 50-200 ms

### 送信電力
```cpp
bleSpam.setTxPower(9); // 最大電力
```
- ESP32範囲: -12 から 9 dBm
- 高い値 = より長い通信距離だが消費電力が高い
- 推奨: 3-6 dBm

### ランダムMAC
```cpp
bleSpam.setRandomMac(true); // ランダムMACを有効化
```
- true = 追跡されにくい
- false = 一貫したMACアドレス

## 一般的な使用例

### 1. 単一デバイススパム
```cpp
void setup() {
    bleSpam.begin("ESP32");
    bleSpam.advertiseAppleDevice(AIRPODS_PRO);
}
```

### 2. 複数デバイスの循環
```cpp
AppleDeviceType devices[] = {AIRPODS_PRO, BEATS_SOLO3, POWERBEATS_PRO};
int currentDevice = 0;

void loop() {
    bleSpam.advertiseAppleDevice(devices[currentDevice]);
    delay(5000);
    bleSpam.stop();
    currentDevice = (currentDevice + 1) % 3;
}
```

### 3. ランダムスパム
```cpp
void loop() {
    int random = random(0, appleDevicesCount);
    bleSpam.advertiseAppleDevice(appleDevices[random].type);
    delay(random(2000, 5000));
    bleSpam.stop();
}
```

## トラブルシューティング

### 問題: "Failed to initialize BLE"
**解決方法:** ESP32ボードを使用していることを確認（ESP8266ではない）

### 問題: ポップアップが表示されない
**解決方法:**
- ESP32をターゲットデバイスに近づける
- 送信電力を上げる: `bleSpam.setTxPower(9);`
- デバイスが脆弱性にパッチを適用済みか確認
- 異なるスパムタイプを試す

### 問題: コンパイルエラー
**解決方法:**
- Arduino IDEにESP32ボードサポートをインストール
- 最新のESP32ボードパッケージに更新
- ライブラリが正しくインストールされているか確認

### 問題: 消費電力が高い
**解決方法:**
- 広告間隔を増やす: `setAdvertisingInterval(200);`
- 送信電力を下げる: `setTxPower(0);`
- 必要ないときは広告を停止: `bleSpam.stop();`

## パフォーマンスのヒント

1. **間隔と電力のバランス:**
   - 速い間隔（50-100ms）+ 高電力（6-9 dBm）= 最大スパム
   - 遅い間隔（200ms以上）+ 低電力（0-3 dBm）= 省電力

2. **ランダムMACを使用:**
   - デバイスにブロックされにくい
   - より効果的なスパム

3. **デバイスを変える:**
   - デバイスを循環させる方が効果的
   - ランダムパターンは固定シーケンスより優れている

## 法的警告

⚠️ **重要:** このツールは教育目的のみです。

- テスト前に必ず許可を得る
- 地域の法律を認識する
- 責任を持って倫理的に使用する
- 他人を嫌がらせたり迷惑をかけたりしない

## サンプルスケッチ

`examples/`フォルダを参照:
1. **AppleBLESpam** - 基本的なAppleデバイススパム
2. **WindowsSwiftPair** - Windowsスパム
3. **SamsungEasySetup** - Samsungスパム
4. **AllDevicesSpam** - マルチプラットフォームスパム
5. **RandomAppleSpam** - 高度なランダムスパム

## リソース

- [完全なドキュメント](README_ja.md)
- [入門ガイド](extras/GettingStarted_ja.md)
- [PlatformIO例](extras/platformio.ini.example)
- [English Documentation](README.md)

## サポート

- GitHub Issues: バグ報告と機能リクエスト
- GitHub Discussions: 質問とアイデアの共有
- Discord: コミュニティに参加（メインリポジトリを参照）

---

**責任を持ってハッキングを楽しんでください! 🚀**
