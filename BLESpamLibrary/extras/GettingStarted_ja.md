# BLESpamライブラリ 入門ガイド

> [日本語版](GettingStarted_ja.md) | [English](GettingStarted.md)

このガイドは、マイコンでBLESpamライブラリを使い始めるのに役立ちます。

## 前提条件

### ハードウェア
- ESP32開発ボード（ESP32、ESP32-S3、ESP32-C3など）
- プログラミング用USBケーブル
- Arduino IDEまたはPlatformIOを搭載したコンピュータ

### ソフトウェア
- Arduino IDE 1.8.13以降またはArduino IDE 2.x
- ESP32ボードサポートパッケージ

## セットアップ手順

### 1. Arduino IDEをインストール

まだインストールしていない場合は、[arduino.cc](https://www.arduino.cc/en/software)からArduino IDEをダウンロードしてインストールしてください。

### 2. ESP32ボードサポートをインストール

1. Arduino IDEを開く
2. **ファイル → 環境設定**に移動
3. 「追加のボードマネージャのURL」に以下を追加:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. **ツール → ボード → ボードマネージャ**に移動
5. "esp32"を検索
6. "esp32 by Espressif Systems"をインストール

### 3. BLESpamライブラリをインストール

インストール手順については、メインのREADME.mdを参照してください。

### 4. ESP32を接続

1. USB経由でESP32ボードをコンピュータに接続
2. Arduino IDEで、**ツール → ボード**に移動してESP32ボードを選択
3. **ツール → シリアルポート**に移動して適切なCOMポートを選択

### 5. 最初のスケッチをアップロード

1. **ファイル → スケッチ例 → BLESpam → AppleBLESpam**に移動
2. **アップロード**ボタン（→）をクリック
3. スケッチがコンパイルされてアップロードされるまで待つ
4. シリアルモニタ（**ツール → シリアルモニタ**）を115200ボーで開く

BLEが初期化され、広告が開始されたことを示す出力が表示されるはずです。

## テスト

### Appleデバイススパムのテスト

1. **AppleBLESpam**の例をESP32にアップロード
2. iPhoneまたはiPadを近くに置く
3. iOS端末に異なるApple製品を表示するポップアップ通知が表示されるはずです

### Windows Swift Pairのテスト

1. **WindowsSwiftPair**の例をESP32にアップロード
2. Bluetoothが有効なWindows 10/11 PCを近くに置く
3. システムトレイにSwift Pair通知が表示されるはずです

### Samsung Easy Setupのテスト

1. **SamsungEasySetup**の例をESP32にアップロード
2. Bluetoothが有効なSamsungスマートフォンを近くに置く
3. Easy Setup通知が表示されるはずです

## トラブルシューティング

### "Failed to initialize BLE!"

**問題:** BLEの初期化に失敗しました。

**解決方法:**
- ESP32ボードを使用していることを確認（ESP8266ではない）
- ボードをリセットしてみる
- ESP32ボードがBLEサポートを持っていることを確認

### ターゲットデバイスにポップアップが表示されない

**問題:** 近くのデバイスに通知が表示されない。

**解決方法:**
- ターゲットデバイスでBluetoothが有効になっていることを確認
- ESP32をターゲットデバイスに近づける
- 送信電力を上げる: `bleSpam.setTxPower(9);`
- 一部のデバイスはこれらの脆弱性にパッチを適用済み
- iOS 17.2以降は一部のApple Continuityポップアップにパッチを適用済み

### アップロードエラー

**問題:** ESP32にスケッチをアップロードできない。

**解決方法:**
- アップロード中にESP32のBOOTボタンを押し続ける
- 正しいCOMポートが選択されていることを確認
- 別のUSBケーブルを試す
- 必要に応じてCP210xまたはCH340ドライバをインストール

### コンパイルエラー

**問題:** スケッチがコンパイルされない。

**解決方法:**
- ESP32ボードサポートがインストールされていることを確認
- 最新のESP32ボードパッケージに更新
- BLESpamライブラリが正しくインストールされているか確認

## 次のステップ

基本的な例が動作したら:

1. **AllDevicesSpam**の例を試して複数のスパムタイプを確認
2. 異なる広告間隔を試す
3. 異なる通信距離のために送信電力を調整
4. 独自のカスタムスパムパターンを作成

## 安全性と法的注意事項

- このツールは**教育目的のみ**です
- 所有していないデバイスでテストする前に必ず許可を得る
- 無線送信に関する地域の法律に注意
- 責任を持って倫理的に使用

## 追加リソース

- [BLESpamライブラリREADME](../README_ja.md)
- [ESP32 BLEドキュメント](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/bluetooth/esp_gap_ble.html)
- [Arduino ESP32ドキュメント](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

## サポート

問題が発生した場合:
1. 上記のトラブルシューティングセクションを確認
2. 既存のGitHub issuesを検索
3. 新しいissueを作成し、以下を含める:
   - ボードモデル
   - Arduino IDEバージョン
   - ESP32ボードパッケージバージョン
   - 完全なエラーメッセージ
   - すでに試したこと

楽しいハッキングを！ 🚀
