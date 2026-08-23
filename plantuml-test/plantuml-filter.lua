function CodeBlock(block)
  if block.classes[1] == "plantuml" then
    local img = pandoc.pipe("plantuml", {"-tsvg", "-pipe"}, block.text)
    return pandoc.RawBlock("html", img)
  end
end
