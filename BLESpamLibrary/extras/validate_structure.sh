#!/bin/bash
# Arduino Library Structure Validation Script

echo "Validating BLESpam Arduino Library Structure..."
echo "=============================================="
echo ""

# Check required files
echo "Checking required files:"
files=(
    "library.properties"
    "keywords.txt"
    "LICENSE"
    "README.md"
    "src/BLESpam.h"
    "src/BLESpam.cpp"
)

missing_files=0
for file in "${files[@]}"; do
    if [ -f "$file" ]; then
        echo "  ✓ $file"
    else
        echo "  ✗ $file (MISSING)"
        missing_files=$((missing_files + 1))
    fi
done
echo ""

# Check examples
echo "Checking examples:"
example_count=$(find examples -name "*.ino" | wc -l)
echo "  Found $example_count example sketches"
if [ $example_count -gt 0 ]; then
    find examples -name "*.ino" | while read -r ino; do
        echo "    ✓ $ino"
    done
else
    echo "  ✗ No example sketches found"
    missing_files=$((missing_files + 1))
fi
echo ""

# Validate library.properties
echo "Validating library.properties:"
if [ -f "library.properties" ]; then
    required_fields=("name" "version" "author" "sentence" "category")
    for field in "${required_fields[@]}"; do
        if grep -q "^${field}=" library.properties; then
            echo "  ✓ $field"
        else
            echo "  ✗ $field (MISSING)"
            missing_files=$((missing_files + 1))
        fi
    done
else
    echo "  ✗ library.properties not found"
fi
echo ""

# Summary
echo "=============================================="
if [ $missing_files -eq 0 ]; then
    echo "✅ Library structure is valid!"
    exit 0
else
    echo "❌ Library structure has $missing_files issue(s)"
    exit 1
fi
