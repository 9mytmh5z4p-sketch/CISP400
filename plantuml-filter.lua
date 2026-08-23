function CodeBlock(block)
  if block.classes:includes("plantuml") then
    local img = pandoc.pipe("plantuml", {"-tsvg", "-pipe"}, block.text)
    return pandoc.RawBlock("html", img)
  end
end
