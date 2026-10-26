import { defineConfig } from "vitepress"
import { generateSidebar } from "vitepress-sidebar"
import { withMermaid } from "vitepress-plugin-mermaid"

const sidebarOptions = {
  excludePattern: ["README.md"],
  excludeFilesByFrontmatterFieldName: "exclude",
  sortMenusByFrontmatterOrder: true,
  useFolderTitleFromIndexFile: true,
  useTitleFromFileHeading: true,
  useTitleFromFrontmatter: true,
}

export default withMermaid(
  defineConfig({
    title: "Adequate SolarCold",
    description: "Engineering and operations documentation for the Adequate Infosoft SolarCold Platform",
    lang: "en-US",
    cleanUrls: true,
    vite: { publicDir: ".public" },
    srcExclude: ["README.md"],
    ignoreDeadLinks: "localhostLinks",
    themeConfig: {
      siteTitle: "Adequate SolarCold",
      nav: [
        { text: "Overview", link: "/" },
        { text: "Operations", link: "/api-examples" },
      ],
      sidebar: generateSidebar(sidebarOptions),
      search: { provider: "local" },
      footer: {
        message: "Maintained by Adequate Infosoft",
        copyright: "Upstream and third-party notices are preserved in LICENSE and NOTICE.md",
      },
    },
  }),
)
