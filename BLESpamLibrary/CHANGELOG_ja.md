# 変更履歴

> [日本語版](CHANGELOG_ja.md) | [English](CHANGELOG.md)

BLESpamライブラリのすべての重要な変更は、このファイルに記録されます。

このフォーマットは[Keep a Changelog](https://keepachangelog.com/en/1.0.0/)に基づいており、
このプロジェクトは[セマンティックバージョニング](https://semver.org/spec/v2.0.0.html)に準拠しています。

## [1.0.0] - 2024-02-11

### 追加
- BLESpam Arduinoライブラリの初回リリース
- 完全なBLE機能を備えたESP32プラットフォームサポート
- Apple Continuity広告サポート
  - 17種類のAppleデバイスタイプ（AirPods、Beatsなど）
  - 新しいデバイスポップアップ生成
  - ランダムなバッテリーレベルとデバイス固有のデータ
- Microsoft Swift Pair広告サポート
  - Windows 10/11ペアリングプロンプト生成
- Samsung Easy Setup広告サポート
  - Samsungデバイスペアリングダイアログ生成
- コアライブラリ機能:
  - 設定可能な広告間隔（20-10240ms）
  - 調整可能な送信電力レベル（ESP32で-12から9 dBm）
  - ランダムMACアドレスサポート
  - 将来の拡張のためのプラットフォーム非依存設計
- 5つのサンプルスケッチ:
  - AppleBLESpam: Appleデバイスを循環
  - WindowsSwiftPair: Windows Swift Pairスパム
  - SamsungEasySetup: Samsung Easy Setupスパム
  - AllDevicesSpam: マルチプラットフォームスパム循環
  - RandomAppleSpam: 高度なランダムデバイススパム
- 包括的なドキュメント:
  - 完全なAPIリファレンスを含むメインREADME.md
  - 日本語README（README_ja.md）
  - 入門ガイド（GettingStarted_ja.md）
  - クイックリファレンス（QUICK_REFERENCE_ja.md）
  - 貢献ガイドライン（CONTRIBUTING_ja.md）
  - PlatformIO設定例
  - Arduino IDEシンタックスハイライト（keywords.txt）
- ライセンスと法的通知:
  - GPL-3.0ライセンス
  - 教育的使用の免責事項
  - 適切な著作権ヘッダー

### 注記
- このライブラリはBluetooth LE Spam Androidアプリに基づいています
- Simon DankelmannおよびBLEセキュリティ研究コミュニティへのクレジット
- 教育および研究目的のみ

## [未リリース]

### 計画中の機能
- nRF52シリーズサポート
- 追加のプラットフォームサポート（nRF Connect SDK、Zephyr）
- より多くのデバイスタイプとスパムパターン
- Webベースの設定インターフェース
- OTAアップデートサポート
- 電力管理の最適化
- 追加のFast Pairデバイスモデル
- Lovespouse/アダルトトイスパムサポート
- BLEスキャナー/検出機能

### 既知の問題
- まだ報告されていません

---

詳細については、[README](README_ja.md)を参照してください。
