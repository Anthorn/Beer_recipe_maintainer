

for f in *.cc.cpp; do
	mv "$f" "$(basename "$f" .cc.cpp).cpp"
done
